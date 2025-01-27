#ifndef _GESTIONES_H
#define _GESTIONES_H




FILE *arc;



FILE* abrirArchivo(char *direccion, char *modo);

void cerrarArchivo(FILE *fp);

void leerArchivo(FILE *fp,char *lec);

void leerArchivoConEspacios(FILE *fp,char *lec, int tam);

void escribirArchivo(FILE *fp,char *esc);

void renombrarArchivo(FILE *fp,char *nom_ant, char *nom_nue);

void eliminarArchivo(char *direccion);

void obtenerLineaArchivo(FILE *fp,char *linea,int tam_linea ,int num_linea);

void obtenerUltimaLineaArchivo(FILE *fp,char *linea,int tam_linea);

void reemplazarLineaArchivo(FILE *fp,char *nueva_linea,int num_linea,char *direccion);

#endif
