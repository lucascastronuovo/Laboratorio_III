#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/shm.h>
#include "threads.h"
#include "global.h"
#include "definiciones.h"
#include "colas.h"
#include "memcomp.h"
#include "utiles.h"


int main(int argc, char *argv[]){

	int id_cola_mensajes;
	int i;
	int id_memoria;

	pthread_t* idHilo = (pthread_t *)malloc(sizeof(pthread_t)*CANT_JUGADORES);
	pthread_attr_t atributos;
	pthread_mutex_init(&mutex,0);
	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
	pthread_attr_init(&atributos);
	pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);
	
	datos_threads = (jugador*)malloc(sizeof(jugador)*CANT_JUGADORES);
					printf("Cola id p: %d\n", id_cola_mensajes);
	
	
	memoria = (inicializado*)creo_memoria(sizeof(inicializado)*CANT_JUGADORES, &id_memoria, CLAVE_BASE);
	configurarMemoriaInicial(&memoria[0].ini);

	memoria[0].ini=0;
	
	verificarMemoriaInicial(&memoria[0].ini);
	shmdt ((char *)memoria);
	shmctl (id_memoria, IPC_RMID, (struct shmid_ds *)0);
	borrar_mensajes(id_cola_mensajes);

	for(i=0;i<CANT_JUGADORES;i++){

		datos_threads[i].nro_jugador = i;
		datos_threads[i].id_cola_mensajes = id_cola_mensajes;
		pthread_create(&idHilo[i],&atributos,threadJugador,&datos_threads[i]);
				
	}

	for(i=0;i<CANT_JUGADORES;i++){
		pthread_join(idHilo[i],0);
		printf("Finalizó el jugador %d\n", datos_threads[i].nro_jugador);
	}
	

	free(datos_threads);
	free(idHilo);

	return 0;
	
	

}
