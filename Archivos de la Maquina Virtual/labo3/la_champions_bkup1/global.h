#ifndef _GLOBAL_H
#define _GLOBAL_H

typedef enum{
	MSG_NADIE,
	MSG_ARBITRO,
	MSG_JULIAN,
	MSG_LAUTARO
}Destinos;

typedef enum{
	EVT_NINGUNO,
	EVT_GOL,
	EVT_FUERA,
	EVT_PALO,
	EVT_ATAJA
	
}Eventos;


extern Destinos destinos;

extern Eventos eventos;

extern pthread_mutex_t mutex;

extern int* inicializado;



#endif
