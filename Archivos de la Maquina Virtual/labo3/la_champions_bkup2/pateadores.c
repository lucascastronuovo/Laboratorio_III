#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <pthread.h>
#include "colas.h"
#include "global.h"
#include "definiciones.h"
#include "threads.h"

int main(int argc, char *argv[]){

	int id_cola_mensajes;
	int i;
	pthread_t *idHilo;
	pthread_attr_t attr;
	
	
	pateadores = (pateador*)malloc(sizeof(pateador)*(CANT_PATEADORES+1));	

	idHilo=(pthread_t *)malloc(sizeof(pthread_t)*(CANT_PATEADORES+1));
	
	
	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
	

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

	borrar_mensajes(id_cola_mensajes);

	for(i=0;i<CANT_PATEADORES;i++){
		
		pateadores[i].id_cola_mensajes = id_cola_mensajes;
		
		if(i==0){
			pateadores[i].nro_jugador=NRO_JULIAN;
		}
		else if(i==1){

			pateadores[i].nro_jugador=NRO_LAUTARO;
		}		
		
		pthread_create(&idHilo[i],&attr,funcionThread,&pateadores[i]);
	}

	for(i=0;i<CANT_PATEADORES;i++){
		pthread_join(idHilo[i],NULL);
	}

	free(idHilo);
	free(pateadores);
	msgctl (id_cola_mensajes, IPC_RMID, (struct msqid_ds *)NULL);

	return 0;

}
