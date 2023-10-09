//Raúl Melgosa Salvador 70925689Z PB1
#include "Ejercicio1/indice.h"
#include "Ejercicio2/dispersion.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main()
{int i,numReg, numRegDes;
 tipoAlumno reg;
 tipoAlumno * regAlumno;
 FILE *f;
 char dni[10];
 int nCubo, ncuboDes, posReg;


  //Ejercicio1
  printf("======================================================================\n");
  printf("Ejercicio1\n");
  printf("======================================================================\n");

  strcpy(dni,"11543192");      
  i = generaIndice("alumnos.dat", "alumnos.idx");  
  if (i<0) {
      printf("\nFallo %d en la creacion del indice\n", i);
  }
  else {
      printf("\nIndice creado correctamente\n");
  }
  i = busquedaIndice(dni, "alumnos.dat", "alumnos.idx", &reg);   
  if (i<0) {
      printf("\nNo existe alumno con dni %s\n", dni);
  }
  else { 
      printf("Registro con NRR %d",i);
      printf("\t %s %s %s %s %s\n\n",reg.dni,reg.nombre,reg.ape1,reg.ape2,reg.provincia);
  }  
  
  
  
  
  //Ejercicio2 //primero imprimimos todos los registos
  printf("======================================================================\n");
  printf("Ejercicio2\n");
  printf("======================================================================\n");
  
  numRegDes=creaHash("alumnos.dat","alumnos.hash");
  printf("%d Registros DESBORDADOS\n\n",numRegDes);

  i = leeHash("alumnos.hash");

  // Búsqueda de registros
  f=fopen("alumnos.hash","rb");

  strcpy(dni,"7389298"); // Existe en el area PRIMA
  regAlumno=busquedaHash(f, dni, &nCubo, &ncuboDes, &posReg, &i);
  if (i < 0) {
      printf("No existe alumno con dni %s\n",dni);
  }
  else { 
      printf("Registro encontrado en el CUBO %d, posicion %d",nCubo, posReg);
      if (ncuboDes != -1) {
          printf("\tEl cubo de desborde es %d", ncuboDes);
      }
      printf("\t %s %s %s %s %s\n",regAlumno->dni,regAlumno->nombre,regAlumno->ape1,regAlumno->ape2,regAlumno->provincia);
  }
  
  strcpy(dni,"7219752"); // Existe en el area De DESBORDE
  regAlumno=busquedaHash(f, dni, &nCubo, &ncuboDes, &posReg, &i);
  if (i < 0) {
      printf("No existe alumno con dni %s\n",dni);
  }
  else { 
      printf("Registro encontrado en el CUBO %d, posicion %d",nCubo, posReg);
      if (ncuboDes != -1) {
          printf("\tEl cubo de desborde es %d", ncuboDes);
      }
      printf("\t %s %s %s %s %s\n",regAlumno->dni,regAlumno->nombre,regAlumno->ape1,regAlumno->ape2,regAlumno->provincia);
  }
  strcpy(dni,"123456789"); // No existe
  regAlumno=busquedaHash(f, dni, &nCubo, &ncuboDes, &posReg, &i);
  if (i < 0) {
      printf("\nNo existe alumno con dni %s\n",dni);
  }
  else { 
      printf("Registro encontrado en el CUBO %d, posicion %d",nCubo, posReg);
      if (ncuboDes != -1) {
          printf("\tEl cubo de desborde es %d", ncuboDes);
      }
      printf("\t %s %s %s %s %s\n",regAlumno->dni,regAlumno->nombre,regAlumno->ape1,regAlumno->ape2,regAlumno->provincia);
  }

  //Fin de Búsqueda
  printf("\n\n");
  //Modificamos la provincia de los estudiantes
  
  strcpy(dni,"7389298"); // Existe en el area PRIMA
  i=modificarReg("alumnos.hash", dni, "SEVILLA");
  if (i < 0) {
      printf("No existe alumno con dni %s\n",dni);
  }
  else { 
      printf("Registro modificado con exito\n");
  }
  
  strcpy(dni,"7219752"); // Existe en el area De DESBORDE
  i=modificarReg("alumnos.hash", dni, "SEVILLA");
  if (i < 0) {
      printf("No existe alumno con dni %s\n",dni);
  }
  else { 
      printf("Registro modificado con exito\n");
  }
  strcpy(dni,"123456789"); // No existe
  i=modificarReg("alumnos.hash", dni, "SEVILLA"); 
  if (i < 0) {
      printf("\nNo existe alumno con dni %s\n",dni);
  }
  else { 
      printf("Registro modificado con exito\n");
  }
  
  //volvemos a leer el hash para ver que las modificaciones se han realizado correctamente
  printf("\n\n");
  i = leeHash("alumnos.hash");
  
  fclose(f);
  
        
  return 0;
}



