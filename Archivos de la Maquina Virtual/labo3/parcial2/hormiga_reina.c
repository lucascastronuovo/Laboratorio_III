#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include "global.h"
#include "colas.h"
#include "definiciones.h"
#include "memcomp.h"
#include "clave.h"


int main(int argc, char *argv[]){
	
	int i;
	int id_memoria;
	int opc;
	int cantidad;
	int id_cola_mensajes;
	int done=0;
	insumos = (insumo*)creo_memoria(sizeof(insumo) * CANT_INSUMOS,&id_memoria,CLAVE_BASE);
	pthread_mutex_init(&mutex,0);
	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

	borrar_mensajes(id_cola_mensajes);

	printf("Elige 4 insumos a juntar:\n");
	
	for(i=0;i<CANT_INSUMOS;i++){
		printf("Juntar:\n");
		insumos[i].nro_insumo = i;
		scanf("%s", &insumos[i].descripcion[0]);

	}
	
	
	for(i=0;i<CANT_INSUMOS;i++){
		printf("Nro insumo: %d - Descripcion: %s\n", insumos[i].nro_insumo,&insumos[i].descripcion[0]);
		

	}
	pthread_mutex_lock(&mutex);
	recibir_mensaje(id_cola_mensajes,MSG_H_REINA,&msg);
	pthread_mutex_unlock(&mutex);
	usleep(500000);
	cantidad = atoi(msg.char_mensaje);

	while(done==0){
		pthread_mutex_lock(&mutex);
		printf("Que opción juntar?:\n");
		while(opc>4 || opc <0){
			scanf("%d", &opc);
		}
		pthread_mutex_unlock(&mutex);
		usleep(50000);
		pthread_mutex_lock(&mutex);
		switch(opc){
			case(0):
				printf("A juntar %s",&insumos[0].descripcion[0]);
				for(i=0;i<cantidad;i++){
					enviar_mensaje(id_cola_mensajes,MSG_H+i,MSG_H_REINA,EVT_JUNTAR_OPC1,&insumos[0].descripcion[0]);
					
				}
				break;
			case(1):
				printf("A juntar %s",&insumos[1].descripcion[0]);
				for(i=0;i<cantidad;i++){
					enviar_mensaje(id_cola_mensajes,MSG_H+i,MSG_H_REINA,EVT_JUNTAR_OPC2,&insumos[1].descripcion[0]);
				}
				break;
			case(2):
				printf("A juntar %s",&insumos[2].descripcion[0]);
				for(i=0;i<cantidad;i++){
					enviar_mensaje(id_cola_mensajes,MSG_H+i,MSG_H_REINA,EVT_JUNTAR_OPC3,&insumos[2].descripcion[0]);
				}
				break;
			case(3):
				printf("A juntar %s",&insumos[3].descripcion[0]);
				for(i=0;i<cantidad;i++){
					enviar_mensaje(id_cola_mensajes,MSG_H+i,MSG_H_REINA,EVT_JUNTAR_OPC4,&insumos[3].descripcion[0]);
				}
				break;
			default:
				break;
		}
		
		recibir_mensaje(id_cola_mensajes,MSG_H_REINA,&msg);
		

		
		switch(msg.int_evento){
			case(EVT_CANTIDAD_TOTAL):
				if(atoi(msg.char_mensaje) >=90)
				printf("fin");
				done=1;
			

		}		
		usleep(500000);

	}


	shmdt((char *)insumos);
	shmctl(id_memoria,IPC_RMID,(struct shmid_ds *)NULL);
	msgctl (id_cola_mensajes, IPC_RMID, (struct msqid_ds *)NULL);
	
	return 0;

}
