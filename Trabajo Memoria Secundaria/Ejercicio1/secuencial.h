#include <stdio.h>

#ifndef __TIPO_ALUMNO
#define __TIPO_ALUMNO
typedef struct {
	char dni[9];
	char nombre[19];
	char ape1[19];
	char ape2[19];
	char provincia[11];
	} tipoAlumno;
#endif

int leeSecuencial(char *fichero);
int buscaReg(FILE *fSecuencial, tipoAlumno *reg,char *dni);
int insertaReg(char *fSecuencial, tipoAlumno *reg);



