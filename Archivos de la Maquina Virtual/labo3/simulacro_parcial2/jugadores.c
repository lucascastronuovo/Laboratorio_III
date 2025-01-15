#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "funciones.h"
#include "colas.h"
#include "global.h"
#include "threads.h"

typedef struct tipo_jugador jugador;
struct tipo_jugador{

	int tipo_jugador;
	int id_cola_mensaje;


};

int main(int argc, char *argv[]){

	int id_cola_mensajes;
	int i=0;
	int cantidad=2;
	pthread_t* idHilo=(pthread_t*)malloc(sizeof(pthread_t)*cantidad);
	pthread_attr_t atributos;
	jugador *datos_thread;
	
	id_cola_mensajes = creo_id_cola_mensajes(33);	

		
		

	pthread_mutex_init(&mutex,0);
	pthread_attr_init(&atributos);
		
	pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);
	
	datos_thread = (jugador*)malloc(sizeof(jugador)*2);


	for(i=0;i<2;i++){
		
		datos_thread[i].tipo_jugador= i;
		datos_thread[i].id_cola_mensaje = id_cola_mensajes;
		if(pthread_create(&idHilo[i], &atributos, &funcionThread, &datos_thread[i])!=0){

					printf("No se pudo crear el thread\n");
					exit (-1);
				}

	}
	

	free(idHilo);
	free(datos_thread);

	return 0;


}
