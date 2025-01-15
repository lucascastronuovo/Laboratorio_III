#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "funciones.h"
#include "global.h"
#include "threads.h"


int main(int argc, char *argv[]){

	
	int hilo_prin[4]; /*hilo_prin[0]: numero pensado  - hilo_prin[1]: estado de acierto - hilo_prin[2]: número de hilo - hilo_prin[3] cantidad de jugadores/hilos*/
	
	
	pthread_attr_t atributos;
	int i;

	if(argc==2){
		
		int cant_jug = atoi(argv[1]); /*esta variable se la podría declarar e instanciar dentro del if que comprueba los parámetros?*/		
		
		static int vec_jug[sizeof(cant_jug)];		

		pthread_t *idHilo=(pthread_t*)malloc(sizeof(pthread_t)*cant_jug);

		pthread_mutex_init(&mutex,0);
		pthread_attr_init(&atributos);
		
		pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

			
		srand(time(NULL));
		hilo_prin[0]=obtenerNumeroAleatorio(1,99);
		hilo_prin[1]=0;
		hilo_prin[3]=cant_jug;
		

		while(hilo_prin[1]==0){
			for(i=0;i<cant_jug && hilo_prin[1]==0;i++){ 
				
				hilo_prin[2]=i;
				if(pthread_create(&idHilo[i], &atributos, &funcionThread, &hilo_prin)!=0){

					printf("No se pudo crear el thread\n");
					exit (-1);
				}
				pthread_join(idHilo[i], 0);
				vec_jug[i]++;
			}
		}

		for(i=0;i<cant_jug;i++){
			printf("Número de intentos del hilo %d: %d\n", i,vec_jug[i]);
		}
		printf(" \n");
		printf(" \n");
		printf("Ganador: Hilo %d\n", hilo_prin[2]);
	
		
		free(idHilo);
	}
	else{
		printf("No se ingresaron los parámetros requeridos\n");
		
	}

	
	
	


	return 0;
}
