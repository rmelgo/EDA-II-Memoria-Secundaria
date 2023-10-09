//Raúl Melgosa Salvador 70925689Z PB1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "indice.h"

int generaIndice(char *ficheroDatos, char *ficheroIndice) {
    FILE *fp;
    FILE *fi;
    tipoAlumno regAlumno;
    tipoIndice regIndice;
    int cont = 0;
    
    fp = fopen(ficheroDatos, "rb");
    if (fp == NULL) {
        return -2;
    }
    
    fi = fopen(ficheroIndice, "w+b");
    if (fi == NULL) {
        return -3;
    }
    
    if (fread(&regAlumno, sizeof(regAlumno), 1, fp) == 0) {
        return -4;
    }
    
    strcpy(regIndice.dni, regAlumno.dni);
    regIndice.NRR = cont;
    if (fwrite(&regIndice, sizeof(regIndice), 1, fi) == 0) {
        return -4;
    }
     
    while (!feof(fp)) {
        cont++;
        if (fread(&regAlumno, sizeof(regAlumno), 1, fp) == 0) {
            if (!feof(fp)) {
                return -4;
            }
            break;
        }
        strcpy(regIndice.dni, regAlumno.dni);
        regIndice.NRR = cont;
        if (fwrite(&regIndice, sizeof(regIndice), 1, fi) == 0) {
            return -4;
        }
    }
    
    fclose(fp);
    fclose(fi);
    return cont;
}

int busquedaIndice(char *dni, char *fDatos, char *fIndice, tipoAlumno *alumno) {
    FILE * fp;
    FILE * fi;
    tipoIndice regIndice;
    int cont = 0;
    
    fp = fopen(fDatos, "rb");
    if (fp == NULL) {
         return -2;
    }
    
    fi = fopen(fIndice, "rb");
    if (fi == NULL) {
        return -3;
    }

    do {
        if (fread(&regIndice, sizeof(tipoIndice), 1, fi) == 0) {
            return -4;
        }
        if (strcmp(regIndice.dni,dni)==0) { 
            if (fseek(fp, sizeof(tipoAlumno) * cont, SEEK_SET) != 0) {               
                return -4;
            }
            if (fread(alumno, sizeof(tipoAlumno), 1, fp) == 0) {
                return -4;
            }
            fclose(fp);
            fclose(fi);
            return cont;
        }
        cont++;
    }
    while (!feof(fi));
    
    
    fclose(fp);
    fclose(fi);
    return -1;
}
