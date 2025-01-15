#ifndef _GESTIONES_H
#define _GESTIONES_H




FILE *arc;


int abrirArchivo(char *direccion, char *modo);

void cerrarArchivo();

void leerArchivo(char *lec);

void escribirArchivo(char *esc);

void renombrarArchivo(char *na, char *nn);

#endif
