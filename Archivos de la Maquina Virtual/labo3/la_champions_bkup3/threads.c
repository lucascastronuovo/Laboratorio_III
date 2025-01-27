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
	static int goles_lautaro=0;
	static int goles_julian=0;
	char c_goles_lautaro[LARGO];
	char c_goles_julian[LARGO];

	pateador *hilo = (pateador*)parametro;
	

	id_cola_mensajes = hilo->id_cola_mensajes;
	nro_jugador = hilo->nro_jugador;
	
	pthread_mutex_init(&mutex,0);

	while(n<5 || goles_julian == goles_lautaro){
		
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
		memset(&c_goles_lautaro[0], 0x00, sizeof(c_goles_lautaro));
		memset(&c_goles_julian[0], 0x00, sizeof(c_goles_julian));
		strcpy(&contenido[0], &msg.char_mensaje[0]);
		evento = msg.int_evento;



		switch(evento){
		
			case EVT_GOL:
				printf("%s\n\n",&contenido[0]);
				if(nro_jugador==NRO_JULIAN){
					goles_julian+=1;
					sprintf(c_goles_julian,"%d\n",goles_julian);
					enviar_mensaje(id_cola_mensajes,MSG_ARBITRO,MSG_JULIAN,EVT_GOL_JULIAN,c_goles_julian);
				}
				else if(nro_jugador==NRO_LAUTARO){
					goles_lautaro+=1;
					sprintf(c_goles_lautaro,"%d\n",goles_lautaro);
					enviar_mensaje(id_cola_mensajes,MSG_ARBITRO,MSG_LAUTARO,EVT_GOL_LAUTARO,c_goles_lautaro);
				}
				break;
			case EVT_FUERA:
				printf("%s\n\n",&contenido[0]);
				if(nro_jugador==NRO_JULIAN){
					enviar_mensaje(id_cola_mensajes,MSG_ARBITRO,MSG_JULIAN,EVT_NO_GOLES,"");
				}
				else if(nro_jugador==NRO_LAUTARO){
					enviar_mensaje(id_cola_mensajes,MSG_ARBITRO,MSG_LAUTARO,EVT_NO_GOLES,"");
				}
				break;

			case EVT_PALO:
				printf("%s\n\n",&contenido[0]);
				if(nro_jugador==NRO_JULIAN){
					enviar_mensaje(id_cola_mensajes,MSG_ARBITRO,MSG_JULIAN,EVT_NO_GOLES,"");
				}
				else if(nro_jugador==NRO_LAUTARO){
					enviar_mensaje(id_cola_mensajes,MSG_ARBITRO,MSG_LAUTARO,EVT_NO_GOLES,"");
				}
				break;

			case EVT_ATAJA:
				printf("%s\n\n",&contenido[0]);
				if(nro_jugador==NRO_JULIAN){
					enviar_mensaje(id_cola_mensajes,MSG_ARBITRO,MSG_JULIAN,EVT_NO_GOLES,"");
				}
				else if(nro_jugador==NRO_LAUTARO){
					enviar_mensaje(id_cola_mensajes,MSG_ARBITRO,MSG_LAUTARO,EVT_NO_GOLES,"");
				}
				break;
			default:
				break;	

		}

	
		n++;		
	}

	pthread_exit(NULL);
}
