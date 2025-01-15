#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include "colas.h"
#include "definiciones.h"
#include "funciones_colas.h"
#include "global.h"
#include "memcomp.h"


int main(int argc, char *argv[]){
	
	
	int id_memoria, id_cola_mensajes, i;

	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
	
	consumidores = (consumidor*)creo_memoria(sizeof(consumidor) * CANT_CONSUMIDOR,&id_memoria,CLAVE_BASE);
	

	borrar_mensajes(id_cola_mensajes);
	printf("Hola\n");

	for(i=0;i<CANT_CONSUMIDOR;i++){
		
		consumidores[i].codigo_consumidor = i;
		consumidores[i].cantidad_pedidos=0;		
		
	}


	while(1){

		recibir_mensaje(id_cola_mensajes,MSG_MAC,&msg);
		procesar_evento_mac(id_cola_mensajes);

	}

	shmdt((char *)consumidores);
	shmctl(id_memoria,IPC_RMID,(struct shmid_ds *)NULL);

	msgctl (id_cola_mensajes, IPC_RMID, (struct msqid_ds *)NULL);
	

	return 0;


}
