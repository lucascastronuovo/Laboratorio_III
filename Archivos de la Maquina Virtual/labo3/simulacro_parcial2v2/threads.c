#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include "threads.h"
#include "global.h"
#include "funciones.h"
#include "colas.h"


void *threadJugador(void *parametro){

	int nro_jugador;
	int id_cola_mensajes;
	int pasos;
	int done=0;
	char contenido[50];


	
	jugador *datos_threads = (jugador*) parametro;
	
	
	nro_jugador = datos_threads->nro_jugador;
	id_cola_mensajes = datos_threads->id_cola_mensajes;
				printf("Cola id: %d\n", id_cola_mensajes);
	srand(time(NULL));	
	
	while(done==0){

		if(nro_jugador == 0){

			printf("Conejo\n");
			pthread_mutex_lock(&mutex);
			pasos = obtenerNumeroAleatorio(1,5);
			sprintf(&contenido[0],"%d", pasos);
			enviar_mensaje(id_cola_mensajes,MSG_CARRERA,MSG_JUGADOR+nro_jugador,EVT_PASOS_CONEJO,&contenido[0]);

			recibir_mensaje(id_cola_mensajes,MSG_JUGADOR+nro_jugador,&msg);

			switch(msg.int_evento){
			
				case(EVT_RTA_PASOS_CONEJO):
					printf("El conejo avanza %d pasos\n", atoi(msg.char_mensaje));
					break;
				case(EVT_FINALIZADO):
					enviar_mensaje(id_cola_mensajes,MSG_JUGADOR+nro_jugador,MSG_JUGADOR+1,EVT_FINALIZADO,"0");
					printf("Finalizó la carrera\n");
					done=1;
					break;
				case(EVT_DESCANSO):
					printf("El conejo descansa\n");
					pthread_mutex_unlock(&mutex);
					sleep(5);
					break;
				default:
					printf("Evento sin definir\n");
					break;
			}
			pthread_mutex_unlock(&mutex);
			usleep(100000);

		}
		else if(nro_jugador == 1){
			printf("Tortuga\n");
			pthread_mutex_lock(&mutex);
			pasos = obtenerNumeroAleatorio(1,5);
			sprintf(&contenido[0],"%d", pasos);
			enviar_mensaje(id_cola_mensajes,MSG_CARRERA,MSG_JUGADOR+nro_jugador,EVT_PASOS_TORTUGA,&contenido[0]);
			recibir_mensaje(id_cola_mensajes,MSG_JUGADOR+nro_jugador,&msg);
			switch(msg.int_evento){
			
				case(EVT_RTA_PASOS_TORTUGA):
					printf("La tortuga avanza %d pasos\n", atoi(msg.char_mensaje));
					break;
				case(EVT_FINALIZADO):
					enviar_mensaje(id_cola_mensajes,MSG_JUGADOR+nro_jugador,MSG_JUGADOR+0,EVT_FINALIZADO,"1");
					printf("Finalizó la carrera\n");
					done=1;					
					break;
				default:
					printf("Evento sin definir\n");
					break;
			}
			pthread_mutex_unlock(&mutex);
			usleep(500000);
	

		}

	}

	
		


	

	printf("Jugador Num° %d\n", nro_jugador);


}
