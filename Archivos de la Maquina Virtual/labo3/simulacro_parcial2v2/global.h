#ifndef _GLOBAL_H
#define _GLOBAL_H


typedef struct tipo_jugador jugador;
struct tipo_jugador{

	int nro_jugador;
	int id_cola_mensajes;
	

};


typedef enum{
	MSG_NADIE,
	MSG_CARRERA,
	MSG_JUGADOR
}Destinos;

typedef enum{
	EVT_NINGUNO,
	EVT_PASOS_CONEJO,
	EVT_PASOS_TORTUGA,
	EVT_FINALIZADO,
	EVT_RTA_PASOS_CONEJO,
	EVT_RTA_PASOS_CONEJO_NOK,
	EVT_RTA_PASOS_TORTUGA,
	EVT_RTA_PASOS_TORTUGA_NOK,
	EVT_RTA_FINALIZADO,
	EVT_RTA_FINALIZADO_NOK,
	EVT_DESCANSO
	
}Eventos;

typedef struct tipo_inicializado inicializado;
struct tipo_inicializado{

	int ini;
	
	

};


extern jugador *datos_threads;

extern Destinos destinos;

extern Eventos eventos;

extern pthread_mutex_t mutex;

extern inicializado *memoria;


#endif
