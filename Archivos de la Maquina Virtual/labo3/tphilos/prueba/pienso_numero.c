#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "funciones.h"
#include "global.h"
#include "threads.h"
	static int n=2;


int main(int argc, char *argv[]){

	
	

	pthread_attr_t atributos;
	int i;

	
		
		int cant_jug = 2;   /*esta variable se la podría declarar e instanciar dentro del if que comprueba los parámetros?*/		
				
		pthread_t *idHilo=(pthread_t*)malloc(sizeof(pthread_t)*cant_jug);

		pthread_mutex_init(&mutex,0);
		pthread_attr_init(&atributos);

		pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

		
		
		
			for(i=0;i<cant_jug ;i++){ 
				printf("Hilo %d\n", i);
				
				if(pthread_create(&idHilo[i], &atributos, &funcionThread, &n)!=0){

					printf("No se pudo crear el thread\n");
					exit (-1);
				}

				if(pthread_create(&idHilo[i], &atributos, &funcionThread2, &n)!=0){

					printf("No se pudo crear el thread\n");
					exit (-1);
				}
				pthread_join(idHilo[i], 0);
				
			}
		

		
	
		
		free(idHilo);
	
	

	
	
	


	return 0;
}
