#ifndef _GESTIONES_H
#define _GESTIONES_H

FILE *arcesc;

FILE *arclec;

void abrirMenu();

int abrirArchivo(char *direccion, char *modo);

void cerrarArchivo(char *modo);

void leerArchivo(char *lec, int a);

void escribirArchivo(char *esc, int n, int a);

#endif