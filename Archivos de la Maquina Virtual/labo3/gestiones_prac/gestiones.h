#ifndef _GESTIONES_H
#define _GESTIONES_H




FILE *arc;

FILE *temp;

FILE* abrirArchivo3(char *direccion, char *modo);

void abrirArchivo2(FILE **fp,char *direccion, char *modo);

int abrirArchivo(char *direccion, char *modo);

void cerrarArchivo2(FILE *fp);

void cerrarArchivo();

void leerArchivo(char *lec);

void leerArchivoConEspacios(char *lec, int tam);

void escribirArchivo2(FILE *fp,char *esc);

void escribirArchivo(char *esc);

void renombrarArchivo(char *nom_ant, char *nom_nue);

void eliminarArchivo(char *direccion);

void obtenerLineaArchivo(char *linea,int tam_linea ,int num_linea);

void obtenerUltimaLineaArchivo(char *linea,int tam_linea);

void reemplazarLineaArchivo(char *nueva_linea,int num_linea,char *direccion);

#endif
