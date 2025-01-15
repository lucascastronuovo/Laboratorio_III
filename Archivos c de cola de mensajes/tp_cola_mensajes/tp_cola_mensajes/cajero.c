#include "stdlib.h"
#include "stdio.h"
#include "clave.h"
#include "colas.h"
#include "memoria.h"
#include "colas.h"
#include "semaforos.h"
#include "definiciones.h"

void menu(int id_cola, mensaje msg, int num_cliente){
	int opcion = 0;
	int monto = 0;	
	char contenido[50];
	char num_cli[50];
	
	memset(num_cli,0x00,sizeof(num_cli));
	memset(contenido,0x00,sizeof(contenido));
	
	printf("Elija una operacion a realizar\n");
	printf("1) Consultar saldo\n");
	printf("2) Hacer un deposito\n");
	printf("3) Realizar una extraccion\n");
	printf("0) Salir\n");
	scanf("%d", &opcion);

	switch(opcion){
		case 1:
			sprintf(num_cli, "%d", num_cliente);
			enviar_mensaje(id_cola, MSG_BANCO, MSG_CAJERO, EVT_CONSULTA_SALDO, num_cli);
			break;
		case 2:
			printf("Ingrese cantidad que desea depositar: \n");
			scanf("%d", &monto);
			sprintf(contenido, "%d,%d", num_cliente, monto);
			enviar_mensaje(id_cola, MSG_BANCO, MSG_CAJERO, EVT_DEPOSITO, contenido);
			break;
		case 3: 
			printf("Ingrese cantidad que desea extraer: \n");
			scanf("%d", &monto);
			sprintf(contenido, "%d,%d", num_cliente, monto);
			enviar_mensaje(id_cola, MSG_BANCO, MSG_CAJERO, EVT_EXTRACCION, contenido);
			break;
		case 0:
			printf("Operacion finalizada\n");
			break;
		default:
			printf("operacion invalida\n");		
	}

}

void ingreso(int id_cola, mensaje msg){
	int num_cli;	
	printf("Ingrese su numero de cliente: \n");
	scanf("%d", &num_cli);
	while(num_cli<1000 || num_cli>1100){
		printf("Numero incorrecto, ingrese nuevamente: \n");
		scanf("%d", &num_cli);	
	}
	
	menu(id_cola, msg, num_cli); 
}

void procesar_evento(int id_cola, mensaje msg){
	switch(msg.int_evento){
		case EVT_RTA_SALDO:
			printf("%s\n",msg.char_mensaje);
			break;
		case EVT_RTA_DEPOSITO_OK:
			printf("%s\n",msg.char_mensaje);			
			break;	
		case EVT_RTA_EXTRACCION_OK:
			printf("%s\n",msg.char_mensaje);
			break;
		case EVT_RTA_EXTRACCION_NOK:
			printf("%s\n",msg.char_mensaje);
			break;
		default:
			break;	
	}
}

int main(int incant,char *argv[])
{
	int id_memoria, id_prendido;
	int id_cola_mensajes;
	cliente *clientes = NULL;
	int *prendido = NULL;
	mensaje msg;

	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
	clientes = (cliente*)creo_memoria(sizeof(cliente)*CANT_CLIENTES, &id_memoria, CLAVE_BASE);
	prendido = (int*)creo_memoria(sizeof(int), &id_prendido, CLAVE_BASE);		
	
	/*while(prendido[0]!=1){
		printf("Inicialice primero banco.c y luego presione ENTER\n");	
		getchar();		
	}*/
	borrar_mensajes(id_cola_mensajes);

	while(1){
		ingreso(id_cola_mensajes, msg);
		recibir_mensaje(id_cola_mensajes, MSG_CAJERO, &msg);
		procesar_evento(id_cola_mensajes, msg);
	}

	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

	shmdt((char *)clientes);
	shmctl(id_memoria, IPC_RMID, (struct shmid_ds *)NULL);
	shmdt((char *)prendido);
	shmctl(id_prendido, IPC_RMID, (struct shmid_ds *)NULL);	

	return 0;
}


