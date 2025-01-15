#ifndef _GLOBAL_H
#define _GLOBAL_H




typedef enum{
	MSG_NADIE,
	MSG_REINA,
	MSG_HORMIGAS
}Destinos;

typedef enum{
	EVT_NINGUNO,
	EVT_JUNTAR_1,
	EVT_JUNTAR_2,
	EVT_JUNTAR_3,
	EVT_JUNTAR_4
	
	
}Eventos;



extern Destinos destinos;

extern Eventos eventos;

extern pthread_mutex_t mutex;

extern int* inicializado;


#endif
