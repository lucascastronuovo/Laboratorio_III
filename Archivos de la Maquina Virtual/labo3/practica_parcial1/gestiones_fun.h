#ifndef _GESTIONES_FUN_H
#define _GESTIONES_FUN_H


void escribir(char *direccion,char *modo,char *esc);

void leer(char *direccion, char *modo);

void leerConEspacios(char *direccion, char *modo);

void ultimaLinea(char *direccion,char *modo,char *linea);

void lineaEspecifica(char *direccion,char *modo,char *linea,int num_linea);

#endif
