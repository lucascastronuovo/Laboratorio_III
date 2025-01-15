#ifndef _GLOBAL_H
#define _GLOBAL_H



typedef struct tipo_juego juego;
struct tipo_juego{

	char nombre_jugador[100];
	int numero_pensado;
	int estado_acierto;

};


extern juego *memoria;

extern int* inicializado;



#endif
