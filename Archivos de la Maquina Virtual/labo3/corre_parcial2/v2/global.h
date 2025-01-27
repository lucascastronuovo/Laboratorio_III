#ifndef _GLOBAL_H
#define _GLOBAL_H

typedef struct t_insumos insumos;
struct t_insumos{

	char descripcion[50];
	int cant_insumo;


};

typedef struct t_estados estados;
struct t_estados{

	int cant_hormigas;
	int done;
	

};

typedef struct t_hormigas hormigas;
struct t_hormigas{
	
	int nro_hormiga;
	int id_cola_mensajes;
	int id_semaforo;
	

};


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


extern insumos *m_insumos;

extern estados *m_estados;

extern hormigas *h_hormigas;

extern Destinos destinos;

extern Eventos eventos;

extern pthread_mutex_t mutex;

extern int* inicializado;


#endif
