#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "funciones.h"
#include "global.h"
#include "threads.h"

struct tipo_juego{

	
	int numero_pensado;
	int estado_acierto;

};


int main(int argc, char *argv[]){

	int cant_jug = atoi(argv[1]); /*esta variable se la podría declarar e instanciar dentro del if que comprueba los parámetros?*/
	struct tipo_juego *juego= (struct tipo_juego*)malloc(sizeof(struct tipo_juego)*(argc-1));
	pthread_t *idHilo=(pthread_t*)malloc(sizeof(pthread_t)*cant_jug);
	pthread_attr_t atributos;
	int i;

	if(argc==2){

		pthread_mutex_init(&mutex,0);
		pthread_attr_init(&atributos);
		
		pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

		


		printf("Cantidad de jugadores: %d\n", cant_jug);		
		srand(time(NULL));
		juego->numero_pensado=obtenerNumeroAleatorio(1,99);
		juego->estado_acierto=0;

		for(i=0;i<cant_jug;i++){ 
			if((pthread_create(&idHilo[i], &atributos, funcionThread, &juego))!=0){

				printf("No se pudo crear el thread\n");
				exit (-1);
			}
		}
		printf("Número generado: %d  Estado acierto: %d\n", juego->numero_pensado, juego->estado_acierto);

		


	}
	else{
		printf("No se ingresaron los parámetros requeridos\n");
		
	}
	
	
	free(juego);
	free(idHilo);

	return 0;
}
