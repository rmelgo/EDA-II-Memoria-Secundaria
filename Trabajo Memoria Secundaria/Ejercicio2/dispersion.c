//Raúl Melgosa Salvador 70925689Z PB1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dispersion.h"

// Crea un fichero hash inicialmente vacio seg�n los criterios especificados en la pr�ctica
// Primera tarea a realizar para  crear un fichero organizado mediante DISPERSI�N
void creaHvacio(char *fichHash)
{ FILE *fHash;
  tipoCubo cubo;
  int j;
  int numCubos =CUBOS+CUBOSDESBORDE;

  memset(&cubo,0,sizeof(cubo));

  fHash = fopen(fichHash,"wb");
  for (j=0;j<numCubos;j++) fwrite(&cubo,sizeof(cubo),1,fHash);
  fclose(fHash);
}
// Lee el contenido del fichero hash organizado mediante el m�todo de DISPERSI�N seg�n los criterios
// especificados en la pr�ctica. Se leen todos los cubos completos tengan registros asignados o no. La
// salida que produce esta funci�n permite visualizar el m�todo de DISPERSI�N

int leeHash(char *fichHash)
{ FILE *f;
  tipoCubo cubo;
  int j,i=0;
  size_t numLee;

   f = fopen(fichHash,"rb");
   rewind(f);
   fread(&cubo,sizeof(cubo),1,f);
   while (!feof(f)){
	for (j=0;j<C;j++) {
        if (j==0)    	printf("Cubo %2d (%2d reg. ASIGNADOS)",i,cubo.numRegAsignados);
        else  	printf("\t\t\t");
	if (j < cubo.numRegAsignados) 
		    printf("\t%s %s %s %s %s\n",
	    		cubo.reg[j].dni,
			cubo.reg[j].nombre,
			cubo.reg[j].ape1,
		  	cubo.reg[j].ape2,
  	                cubo.reg[j].provincia);
	else printf ("\n");
        }
       i++;
       fread(&cubo,sizeof(cubo),1,f);
   }
   fclose(f);
   return i;
}

int creaHash(char *fichEntrada,char *fichHash) {
    FILE *fEntrada, *fHash;
    tipoAlumno reg;
    tipoCubo cubo;
    fpos_t pos;
    int i, numDesb = 0, j;

    creaHvacio(fichHash);
    fEntrada = fopen(fichEntrada, "rb");
    fHash = fopen(fichHash, "r+b"); 
    fread(&reg, sizeof(reg), 1, fEntrada);
    while (!feof(fEntrada)) {
        fseek(fHash, (atoi(reg.dni)%CUBOS)*sizeof(cubo), SEEK_SET);
        fgetpos(fHash, &pos);
        fread(&cubo, sizeof(cubo), 1, fHash);
        i = cubo.numRegAsignados;
        if (i >= C) {
            numDesb++;
            cubo.numRegAsignados++;   
            j = 0;                      
            while (j < CUBOSDESBORDE) {   
                fsetpos(fHash, &pos);
                fwrite(&cubo, sizeof(cubo), 1, fHash);         
                fseek(fHash, (CUBOS + j) * sizeof(cubo), SEEK_SET);
                fgetpos(fHash, &pos);
                fread(&cubo, sizeof(cubo), 1, fHash);
                i = cubo.numRegAsignados;
                if (i >= C) {           
                    cubo.numRegAsignados++; 
                    j++;
                }
                else {
                    cubo.reg[i] = reg;
                    cubo.numRegAsignados++;
                    break;
                }
            }
        } else {
            cubo.reg[i] = reg;
            cubo.numRegAsignados++;
        }
        fsetpos(fHash, &pos);
        fwrite(&cubo, sizeof(cubo), 1, fHash);
        fread(&reg, sizeof(reg), 1, fEntrada);
    }
    fclose(fEntrada);
    fclose(fHash);
    return numDesb;
}

tipoAlumno * busquedaHash(FILE *f, char *dni,int *nCubo, int *ncuboDes, int *posReg, int *error) {
    tipoAlumno * alumno;
    tipoCubo cubo;
    int i, num_cubo, num_cubo_des;

    f = fopen("alumnos.hash", "rb");
    if (f == NULL) {
        *error = -2;
        return NULL;
    }
    
    num_cubo = atoi(dni) % CUBOS;
    fseek(f, sizeof(tipoCubo) * num_cubo, SEEK_SET);
    fread(&cubo, sizeof(tipoCubo), 1, f);
    for (i = 0; i < C; i++) {
        if (strcmp(cubo.reg[i].dni, dni) == 0) {
            *nCubo = num_cubo;
            *ncuboDes = -1;
            *posReg = i;
            *error = 0;
            alumno = &(cubo.reg[i]);
            return alumno;
        }
    }
    
    for (num_cubo_des = 0; num_cubo_des < CUBOSDESBORDE; num_cubo_des++) {
        fseek(f, (CUBOS + num_cubo_des) * sizeof(tipoCubo), SEEK_SET);
        fread(&cubo, sizeof(tipoCubo), 1, f);
        for (i = 0; i < C; i++) {
            if (strcmp(cubo.reg[i].dni, dni) == 0) {
                *nCubo = num_cubo;
                *ncuboDes = num_cubo_des + CUBOS;
                *posReg = i;
                *error = 0;               
                alumno = &(cubo.reg[i]);
                return alumno;
            }
        }
    }

    *error = -1;
    return NULL;
}

int modificarReg(char * fichero, char * dni, char * provincia) {
    FILE *f;
    tipoAlumno *regAlumno;
    tipoAlumno reg;
    tipoCubo cubo;
    fpos_t pos;
    int numeroCubo, numeroCuboDesborde, posicionRegistro, error;
    int i;

    regAlumno = busquedaHash(f, dni, &numeroCubo, &numeroCuboDesborde, &posicionRegistro, &error);
    if (error != 0) {
        return error;
    }
    
    f = fopen("alumnos.hash", "r+b");
    if (f == NULL) {
        return -2;
    }
    

    if (numeroCuboDesborde == -1) {
        fseek(f, (numeroCubo * sizeof(cubo)), SEEK_SET);
    }
    else {
        fseek(f, (numeroCuboDesborde * sizeof(cubo)), SEEK_SET);
    }
    
    fgetpos(f, &pos);
    fread(&cubo, sizeof(cubo), 1, f);
    strcpy(cubo.reg[posicionRegistro].provincia, provincia);
    fsetpos(f, &pos);
    fwrite(&cubo, sizeof(cubo), 1, f);

       
    fclose(f);
    return 0;
}

