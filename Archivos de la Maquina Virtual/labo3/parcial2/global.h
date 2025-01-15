#ifndef _GLOBAL_H
#define _GLOBAL_H


typedef struct tipo_insumo insumo;
struct tipo_insumo{

	int nro_insumo;
	char descripcion[50];
	

};


typedef struct tipo_hormiga hormiga;
struct tipo_hormiga{

	int nro_hormiga;
	int id_cola_mensajes;
	int cantidad;
	

};



typedef enum{
	MSG_NADIE,
	MSG_H_REINA,
	MSG_H
}Destinos;

typedef enum{
	EVT_NINGUNO,
	EVT_JUNTAR_OPC1,
	EVT_JUNTAR_OPC2,
	EVT_JUNTAR_OPC3,
	EVT_JUNTAR_OPC4,
	EVT_CANTIDAD,
	EVT_CANTIDAD_TOTAL,
	EVT_FINALIZADO
	
}Eventos;



extern insumo *insumos;

extern hormiga *datos_threads;

extern Destinos destinos;

extern Eventos eventos;

extern pthread_mutex_t mutex;




#endif
