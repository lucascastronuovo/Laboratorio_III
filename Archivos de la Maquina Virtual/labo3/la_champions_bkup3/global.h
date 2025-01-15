#ifndef _GLOBAL_H
#define _GLOBAL_H

typedef struct tipo_resultado resultado;
struct tipo_resultado{
		
	int goles_julian;
	int goles_lautaro;
	int done;

};

typedef struct tipo_pateador pateador;
struct tipo_pateador{

	int nro_jugador;
	int id_cola_mensajes;

};



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
	EVT_ATAJA,
	EVT_GOL_JULIAN,
	EVT_GOL_LAUTARO,
	EVT_NO_GOLES
	
}Eventos;

extern resultado *m_resultado;

extern pateador *pateadores;

extern Destinos destinos;

extern Eventos eventos;

extern pthread_mutex_t mutex;

extern int* inicializado;



#endif
