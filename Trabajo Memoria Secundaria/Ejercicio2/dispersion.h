#include <stdio.h>
#define C 5	                // capacidad del cubo
#define CUBOS 20           // Número de cubos en el area prima
#define CUBOSDESBORDE  4   // Número de cubos area de desborde

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

typedef struct {
	tipoAlumno reg[C];
	int cuboDES;      // De momento no la vamos a utilizar
	int numRegAsignados;
	}tipoCubo;

// funciones proporcionadas
void creaHvacio(char *fichHash);
int leeHash(char *fichHash);
// funciones a codificar
int creaHash(char *fichEntrada,char *fichHash);
int buscaReg(FILE *fHash, tipoAlumno *reg,char *dni);

tipoAlumno * busquedaHash(FILE *f, char *dni,int *nCubo, int *ncuboDes, int *posReg, int *error);
int modificarReg(char * fichero, char * dni, char * provincia);



