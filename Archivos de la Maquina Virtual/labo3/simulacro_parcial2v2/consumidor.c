#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>
#include "colas.h"
#include "definiciones.h"
#include "funciones_colas.h"
#include "global.h"
#include "memcomp.h"


int main(int argc, char *argv[]){
	
	
	int id_memoria, id_cola_mensajes, cod, opc, cantidad;
	char c_cod[50];
	char c_cantidad[50];
	
	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
	
	consumidores = (consumidor*)creo_memoria(sizeof(consumidor) * CANT_CONSUMIDOR,&id_memoria,CLAVE_BASE);
	

	borrar_mensajes(id_cola_mensajes);
	
	while(1){
		memset(&c_cod[0],0x00,sizeof(c_cod));
		memset(&c_cantidad[0],0x00,sizeof(c_cantidad));

		printf("Ingrese codigo de cliente:\n");
		scanf("%d", &cod);
		sprintf(&c_cod[0], "%d", cod);
		
		printf("Operación:\n");
		printf("1) Consulta cantidad pedidos\n");
		printf("2) Agregar pedidos\n");
		printf("0) Salir\n");
		scanf("%d",&opc);
		
		
		switch(opc){

			case 1:
				enviar_mensaje(id_cola_mensajes,MSG_MAC,MSG_CONS,EVT_CONSULTA_PEDIDO,&c_cod[0]);
				break;
			case 2:
				printf("Cantidad:\n");
				scanf("%d", &cantidad);
				sprintf(&c_cantidad[0], "%d,%d", cod,cantidad);
				enviar_mensaje(id_cola_mensajes,MSG_MAC,MSG_CONS,EVT_AGREGAR_PEDIDO,&c_cantidad[0]);
				break;

			case 0:
				printf("Finalizado\n");
				break;
			default:
				printf("Operación inválida\n");
				break;
			

		}
		recibir_mensaje(id_cola_mensajes, MSG_CONS,&msg);
		procesar_evento_cons(id_cola_mensajes);
	}

	shmdt((char *)consumidores);
	shmctl(id_memoria,IPC_RMID,(struct shmid_ds *)NULL);

	msgctl (id_cola_mensajes, IPC_RMID, (struct msqid_ds *)NULL);

	return 0;


}
