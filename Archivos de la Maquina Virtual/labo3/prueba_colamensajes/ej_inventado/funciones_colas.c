#include <stdio.h>
#include <stdlib.h>
#include "colas.h"
#include "global.h"

void procesar_evento_mac(int id_cola_mensajes){

	char cadena[50];
	int num_con;
	int cant;
	int i=0;
	
	switch(msg.int_evento){

		case EVT_CONSULTA_PEDIDO:
			num_con = atoi(msg.char_mensaje);
			if(num_con < 0){
				sprintf(cadena, "Consumidor Invalido\n");
				enviar_mensaje(id_cola_mensajes,msg.int_rte,MSG_MAC,EVT_RTA_PEDIDO_NOK, cadena);
			}
			else{
				sprintf(cadena, "Cantidad pedidos del consumidor %d: %d\n", num_con, consumidores[num_con].cantidad_pedidos);
				enviar_mensaje(id_cola_mensajes,msg.int_rte,MSG_MAC,EVT_RTA_PEDIDO, cadena);
			}			
			break;

		case EVT_AGREGAR_PEDIDO:
			sscanf(msg.char_mensaje, "%d,%d", &num_con, &cant);
			if(num_con < 0 || cant <= 0){
				sprintf(cadena, "Consumidor Invalido o cantidad ingresada inválida\n");
				enviar_mensaje(id_cola_mensajes,msg.int_rte,MSG_MAC,EVT_RTA_AGREGAR_PEDIDO_NOK, cadena);
			}
			else{
				consumidores[num_con].cantidad_pedidos = consumidores[num_con].cantidad_pedidos + cant;
				sprintf(cadena, "Cantidad de pedidos del cliente %d ingresados: %d\n", num_con, cant);
				enviar_mensaje(id_cola_mensajes,msg.int_rte,MSG_MAC,EVT_RTA_AGREGAR_PEDIDO_OK, cadena);
			}
	

		default:
			break;

	}


}

void procesar_evento_cons(int id_cola_mensajes){

	switch(msg.int_evento){

		case EVT_RTA_PEDIDO:
			printf("%s\n",msg.char_mensaje);			
			break;

		case EVT_RTA_PEDIDO_NOK:
			printf("%s\n",msg.char_mensaje);
			break;
		case EVT_RTA_AGREGAR_PEDIDO_OK:
			printf("%s\n",msg.char_mensaje);
			break;
		case EVT_RTA_AGREGAR_PEDIDO_NOK:
			printf("%s\n",msg.char_mensaje);
			break;

		default:
			break;

	}


}



