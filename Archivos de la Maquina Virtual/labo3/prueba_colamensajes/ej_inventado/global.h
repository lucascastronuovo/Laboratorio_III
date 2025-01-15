#ifndef _GLOBAL_H
#define _GLOBAL_H


typedef struct tipo_consumidor consumidor;
struct tipo_consumidor{

	int codigo_consumidor;
	int cantidad_pedidos;

};


typedef enum{
	MSG_NADIE,
	MSG_MAC,
	MSG_CONS
}Destinos;

typedef enum{
	EVT_NINGUNO,
	EVT_CONSULTA_PEDIDO,
	EVT_AGREGAR_PEDIDO,
	EVT_RTA_PEDIDO,
	EVT_RTA_PEDIDO_NOK,
	EVT_RTA_AGREGAR_PEDIDO_OK,
	EVT_RTA_AGREGAR_PEDIDO_NOK
	
}Eventos;

extern consumidor *consumidores;

extern Destinos destinos;

extern Eventos eventos;

#endif
