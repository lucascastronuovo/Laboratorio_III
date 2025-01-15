#include "stdlib.h"
#include "stdio.h"
#include "clave.h"
#include "colas.h"
#include "memoria.h"
#include "colas.h"
#include "semaforos.h"
#include "definiciones.h"

void procesar_evento(int id_cola, mensaje msg, cliente *clientes){
	char cadena[50];
	int num_cli = 0;
	int monto = 0;	
	int i = 0;	
	printf("Procesar evento\n");
	switch(msg.int_evento){
		case EVT_CONSULTA_SALDO:
			num_cli = atoi(msg.char_mensaje);
			i = num_cli - 1000;
			printf("CONSULTA DE SALDO\n");
			sprintf(cadena,"Saldo de Cliente %d: %d\n", num_cli, clientes[i].saldo);
			enviar_mensaje(id_cola, msg.int_rte, MSG_BANCO, EVT_RTA_SALDO, cadena);
			break;
		case EVT_DEPOSITO:
			sscanf(msg.char_mensaje, "%d, %d", &num_cli, &monto);
			printf("Cliente: %d Saldo previo al deposito: %d\n", num_cli, clientes[i].saldo);
			i = num_cli - 1000;
			clientes[i].saldo = clientes[i].saldo + monto;
			printf("DEPOSITO\n");
			sprintf(cadena,"Deposito de Cliente %d: Saldo Actual %d - Monto: %d\n", num_cli, clientes[i].saldo, monto);
			enviar_mensaje(id_cola, msg.int_rte, MSG_BANCO, EVT_RTA_DEPOSITO_OK, cadena);			
			break;	
		case EVT_EXTRACCION:
			sscanf(msg.char_mensaje, "%d, %d", &num_cli, &monto);
			i = num_cli - 1000;
			printf("EXTRACCION\n");
			if(monto > clientes[i].saldo){
				sprintf(cadena,"No hay suficiente saldo\n");
				enviar_mensaje(id_cola, msg.int_rte, MSG_BANCO, EVT_RTA_EXTRACCION_NOK, cadena);			
			}else{
				clientes[i].saldo = clientes[i].saldo - monto;	
				sprintf(cadena,"Extraccion de Cliente %d: Saldo Actual %d - Monto %d\n", num_cli, clientes[i].saldo, monto);
				enviar_mensaje(id_cola, msg.int_rte, MSG_BANCO, EVT_RTA_EXTRACCION_OK, cadena);
			}
			break;
		default:
			break;	
	}
}

int main(int incant,char *argv[])
{
	int id_memoria, id_prendido;
	int id_cola_mensajes;
	int i = 0;
	cliente *clientes = NULL;
	int *prendido = NULL;
	mensaje msg;
	msg.int_evento = 0;
	
	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
	clientes = (cliente*)creo_memoria(sizeof(cliente)*CANT_CLIENTES, &id_memoria, CLAVE_BASE);
	prendido = (int*)creo_memoria(sizeof(int), &id_prendido, CLAVE_BASE);	

	prendido[0] = 1;	
	
	for(i=0;i<CANT_CLIENTES;i++){
		clientes[i].codigo_cliente = i + 1000;
		clientes[i].saldo = 0;	
	}

	borrar_mensajes(id_cola_mensajes);

	printf("BANCO DE LA NACION ARGENTINA\n");
	while(1){
		recibir_mensaje(id_cola_mensajes, MSG_BANCO, &msg);
		procesar_evento(id_cola_mensajes, msg, clientes);
	}

	shmdt((char *)clientes);
	shmctl(id_memoria, IPC_RMID, (struct shmid_ds *)NULL);
	shmdt((char *)prendido);
	shmctl(id_prendido, IPC_RMID, (struct shmid_ds *)NULL);	
		
	return 0;

}

