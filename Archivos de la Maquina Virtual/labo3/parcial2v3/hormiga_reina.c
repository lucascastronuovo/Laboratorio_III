#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/msg.h>
#include <pthread.h>
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
	int cantidad_total_insumos;
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
	printf("Cantidad de hormigas: %d\n", cantidad);
	
	while(done==0){
		
		opc=-1;

		printf("Que opción juntar?:\n");
		while(opc>4 || opc <0){
			scanf("%d", &opc);
		};
		
		
		switch(opc){
			case(0):
				printf("A juntar %s\n",&insumos[0].descripcion[0]);
				for(i=0;i<cantidad;i++){
					pthread_mutex_lock(&mutex);
					enviar_mensaje(id_cola_mensajes,MSG_H+i,MSG_H_REINA,EVT_JUNTAR_OPC1,&insumos[0].descripcion[0]);
					pthread_mutex_unlock(&mutex);
					usleep(100000);
				}
				break;
			case(1):
				printf("A juntar %s\n",&insumos[1].descripcion[0]);
				for(i=0;i<cantidad;i++){
					pthread_mutex_lock(&mutex);
					enviar_mensaje(id_cola_mensajes,MSG_H+i,MSG_H_REINA,EVT_JUNTAR_OPC2,&insumos[1].descripcion[0]);
					pthread_mutex_unlock(&mutex);
					usleep(100000);
				}
				break;
			case(2):
				printf("A juntar %s\n",&insumos[2].descripcion[0]);
				for(i=0;i<cantidad;i++){
					pthread_mutex_lock(&mutex);
					enviar_mensaje(id_cola_mensajes,MSG_H+i,MSG_H_REINA,EVT_JUNTAR_OPC3,&insumos[2].descripcion[0]);
					pthread_mutex_unlock(&mutex);
					usleep(100000);
				}
				break;
			case(3):
				printf("A juntar %s\n",&insumos[3].descripcion[0]);
				for(i=0;i<cantidad;i++){
					pthread_mutex_lock(&mutex);
					enviar_mensaje(id_cola_mensajes,MSG_H+i,MSG_H_REINA,EVT_JUNTAR_OPC4,&insumos[3].descripcion[0]);
					pthread_mutex_unlock(&mutex);
					usleep(100000);
				}
				break;
			default:
				break;
		}
		pthread_mutex_lock(&mutex);
		printf("a\n");
		recibir_mensaje(id_cola_mensajes,MSG_H_REINA,&msg);
		
		pthread_mutex_unlock(&mutex);
		usleep(500000);
		cantidad_total_insumos=	atoi(msg.char_mensaje);
		printf("VALOR %d\n", cantidad_total_insumos);
		switch(msg.int_evento){
			case(EVT_FINALIZA_REINA):

				done=1;
				break;
			

			case(EVT_NO_FINALIZADO):
				printf("SIGUE LA COLECTA\n");				
				break;
			

		}
		

	}


	shmdt((char *)insumos);
	shmctl(id_memoria,IPC_RMID,(struct shmid_ds *)NULL);
	msgctl (id_cola_mensajes, IPC_RMID, (struct msqid_ds *)NULL);
	
	return 0;

}
