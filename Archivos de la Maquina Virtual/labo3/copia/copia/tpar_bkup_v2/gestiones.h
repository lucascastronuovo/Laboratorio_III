#ifndef _GESTIONES_H
#define _GESTIONES_H


/*FILE *arcesc;

FILE *arclec;*/

FILE *arc;

void abrirMenu();


int abrirArchivo(char *direccion, char *modo);

void cerrarArchivo(char *modo);

void leerArchivo(char *lec, int a);

void escribirArchivo(char *esc, int n);


/*


int producir(FILE *pro, int n);

int consumir(FILE *con);
*/

#endif
