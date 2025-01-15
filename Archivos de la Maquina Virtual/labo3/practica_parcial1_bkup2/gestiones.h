#ifndef _GESTIONES_H
#define _GESTIONES_H




FILE *arc;


int abrirArchivo(char *direccion, char *modo);

void cerrarArchivo();

void leerArchivo(char *lec);

void leerArchivoConEspacios(char *lec, int tam);

void escribirArchivo(char *esc);

void renombrarArchivo(char *na, char *nn);

void obtenerLineaArchivo(char *linea,int tam_linea ,int num_linea);

void obtenerUltimaLineaArchivo(char *linea,int tam_linea);

void reemplazarLineaArchivo(char *nueva_linea,int num_linea,char *direccion);

#endif
