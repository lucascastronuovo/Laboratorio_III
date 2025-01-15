#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include "colas.h"
#include "threads.h"
#include "global.h"
#include "definiciones.h"

void *funcionThread(void *parametro){
	
	int id_cola_mensajes, nro_jugador, evento;
	int n=0;
	char contenido[LARGO];

	pateador *hilo = (pateador*)parametro;
	

	id_cola_mensajes = hilo->id_cola_mensajes;
	nro_jugador = hilo->nro_jugador;
	
	pthread_mutex_init(&mutex,0);

	while(n<5){
		
		if(nro_jugador == NRO_JULIAN){
			pthread_mutex_lock(&mutex);
			recibir_mensaje(id_cola_mensajes,MSG_JULIAN,&msg);
			pthread_mutex_unlock(&mutex);
			usleep(100000);

		}
		else if(nro_jugador == NRO_LAUTARO){
			pthread_mutex_lock(&mutex);
			recibir_mensaje(id_cola_mensajes,MSG_LAUTARO,&msg);
			pthread_mutex_unlock(&mutex);
			usleep(100000);

		}

		
	
		memset(&contenido[0], 0x00, sizeof(contenido));
		strcpy(&contenido[0], &msg.char_mensaje[0]);
		evento = msg.int_evento;



		switch(evento){
		
			case EVT_GOL:
				printf("%s\n\n",&contenido[0]);
				break;
			case EVT_FUERA:
				printf("%s\n\n",&contenido[0]);
				break;

			case EVT_PALO:
				printf("%s\n\n",&contenido[0]);
				break;

			case EVT_ATAJA:
				printf("%s\n\n",&contenido[0]);
				break;
			default:
				break;	

		}
			
		n++;		
	}

	pthread_exit(NULL);
}
