#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/msg.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#include "memcomp.h"
#include "definiciones.h"
#include "colas.h"
#include "global.h"
#include "clave.h"
#include "semaforo.h"
#include "funciones.h"
#include "utiles.h"
#include "threads.h"




int main(int argc, char *argv[]){


	int id_semaforo, id_cola_mensajes, id_insumos, id_estados, id_memoria;
	int cant_hormigas, i;
	
	pthread_t *idHilo;
	pthread_attr_t attr;
		
	inicializado = (int*)creo_memoria(sizeof(int), &id_memoria, CLAVE_BASE);
	configurarMemoriaInicial(inicializado);
	
	verificarMemoriaInicial(inicializado);
	shmdt ((char *)inicializado);
	
	id_semaforo =  crearSemaforo();
	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

	m_insumos=(insumos*)creo_memoria(sizeof(insumos) * (CANT_INSUMOS + 1),&id_insumos,CLAVE_BASE);
	m_estados=(estados*)creo_memoria(sizeof(estados)*2,&id_estados,CLAVE_BASE+1);
	

	if (argc == 2){
	
		cant_hormigas=atoi(argv[1]);
		if(cant_hormigas<=0){
			printf("Cantidad de hormigas ingresada no válida\n");
			return 0;
		}


	}
	else{

			printf("Ingrese una cantidad\n");
			return 0;
	

	}

	idHilo=(pthread_t *)malloc(sizeof(pthread_t)*(cant_hormigas+1));
	h_hormigas=(hormigas *)malloc(sizeof(hormigas)*(cant_hormigas+1));
	

	esperarSemaforo(id_semaforo);
	m_estados->cant_hormigas = cant_hormigas;
	levantarSemaforo(id_semaforo);
	usleep(1000);


	

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

	borrar_mensajes(id_cola_mensajes);

	for(i=0;i<cant_hormigas;i++){
		h_hormigas[i].nro_hormiga= i+1;
		h_hormigas[i].id_cola_mensajes = id_cola_mensajes;
		h_hormigas[i].id_semaforo = id_semaforo;
		pthread_create(&idHilo[i],&attr,funcionThread,&h_hormigas[i]);
	}

	for(i=0;i<cant_hormigas;i++){
		pthread_join(idHilo[i],NULL);
	}

	free(idHilo);
	free(h_hormigas);
	
	shmdt((char *)m_insumos);

	shmdt((char *)m_estados);
	msgctl (id_cola_mensajes, IPC_RMID, (struct msqid_ds *)NULL);
	return 0;

}
