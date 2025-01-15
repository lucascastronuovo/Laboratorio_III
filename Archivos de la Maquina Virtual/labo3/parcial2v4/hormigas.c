#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include "memcomp.h"
#include "threads.h"
#include "global.h"
#include "definiciones.h"
#include "colas.h"


int main(int argc, char *argv[]){
	
	int id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
	int i, cantidad;
	int id_memoria;
	pthread_t* idHilo = (pthread_t *)malloc(sizeof(pthread_t)*cantidad);
	pthread_attr_t atributos;

	char contenido[50];
	if(argc==2){		
		cantidad = atoi(argv[1]);
		printf("%d\n", cantidad);

		
		pthread_mutex_init(&mutex,0);

		pthread_attr_init(&atributos);
		pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);
		
		datos_threads = (hormiga*)malloc(sizeof(hormiga)*cantidad);
		insumos = (insumo*)creo_memoria(sizeof(insumo) * CANT_INSUMOS,&id_memoria,CLAVE_BASE);
		borrar_mensajes(id_cola_mensajes);
		sprintf(&contenido[0], "%d", cantidad);
		pthread_mutex_lock(&mutex);
		enviar_mensaje(id_cola_mensajes,MSG_H_REINA,MSG_H,EVT_CANTIDAD,&contenido[0]);
		pthread_mutex_unlock(&mutex);
		usleep(500000);
		for(i=0;i<cantidad;i++){

			datos_threads[i].nro_hormiga = i;
			datos_threads[i].id_cola_mensajes = id_cola_mensajes;
			datos_threads[i].cantidad = cantidad;
			pthread_create(&idHilo[i],&atributos,threadHormiga,&datos_threads[i]);
				
		}
		
		for(i=0;i<cantidad;i++){
			pthread_join(idHilo[i],0);
			
			printf("finalizan la hormiga %d\n", i);
			
		}
	
		/*free(datos_threads);*/
		printf("PAPER\n");
		
	}
	else{

		printf("Ingresar parámetro\n");

	
	}
			/*free(idHilo);*/
			
			shmdt((char *)insumos);
			shmctl(id_memoria,IPC_RMID,(struct shmid_ds *)NULL);
			msgctl (id_cola_mensajes, IPC_RMID, (struct msqid_ds *)NULL);
		

	return 0;

}
