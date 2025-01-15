#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <string.h>
#include "threads.h"
#include "global.h"
#include "funciones.h"
#include "colas.h"


void *threadHormiga(void *parametro){

	int nro_hormiga;
	int id_cola_mensajes;
	int cantidad;
	int cantidad_insumos_total=0;
	char c_cantidad_insumos_total[50];
	int cantidad_insumo;
	int done=0;
	char contenido[50];


	
	hormiga *datos_threads = (hormiga*) parametro;

	
	nro_hormiga = datos_threads->nro_hormiga;
	id_cola_mensajes = datos_threads->id_cola_mensajes;
	cantidad = datos_threads->cantidad;
	printf("Hormiga Nro: %d\n", nro_hormiga);
	srand(time(NULL));	
	
	

	while(done==0){
		pthread_mutex_lock(&mutex);
		recibir_mensaje(id_cola_mensajes,MSG_H+nro_hormiga,&msg);
		pthread_mutex_unlock(&mutex);
		usleep(500000);
		
		memset(&c_cantidad_insumos_total[0],0x00,sizeof(c_cantidad_insumos_total));
		memset(&contenido[0],0x00,sizeof(contenido));
		
		switch(msg.int_evento){

			case(EVT_JUNTAR_OPC1):
				cantidad_insumo= obtenerNumeroAleatorio(1,4);
				printf("Se obtuvo %d del insumo %s\n", cantidad_insumo, &msg.char_mensaje[0]);
				cantidad_insumos_total=cantidad_insumos_total+cantidad_insumo;
			
				
				break;
			case(EVT_JUNTAR_OPC2):
				cantidad_insumo= obtenerNumeroAleatorio(1,4);
				printf("Se obtuvo %d del insumo %s\n", cantidad_insumo, &msg.char_mensaje[0]);
				cantidad_insumos_total=cantidad_insumos_total+cantidad_insumo;
				
				break;
			case(EVT_JUNTAR_OPC3):
				cantidad_insumo= obtenerNumeroAleatorio(1,4);
				printf("Se obtuvo %d del insumo %s\n", cantidad_insumo, &msg.char_mensaje[0]);
				cantidad_insumos_total=cantidad_insumos_total+cantidad_insumo;
				
				
				break;
			case(EVT_JUNTAR_OPC4):
				cantidad_insumo= obtenerNumeroAleatorio(1,4);
				printf("Se obtuvo %d del insumo %s\n", cantidad_insumo, &msg.char_mensaje[0]);
				cantidad_insumos_total=cantidad_insumos_total+cantidad_insumo;
				
				break;

			default:
				printf("Evento indefinido\n");
				break;




		}

		if(cantidad_insumos_total >= 90){
			
			
			done=1;
			
		}



	}

	printf("asdasdas");	

}
