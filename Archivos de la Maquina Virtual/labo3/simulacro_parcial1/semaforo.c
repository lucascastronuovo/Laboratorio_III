#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include "semaforo.h"
#include "defsem.h"
#include "clave.h" 

int crearSemaforo() {

	key_t clave = creo_clave(CLAVE_BASE);
	int id_semaforo = semget(clave, 1, 0600|IPC_CREAT);

	if(id_semaforo == -1){
		
		printf("Error: no puedo crear semaforo\n");
		exit(0);
	
	}
	

	return id_semaforo;

}

void iniciarSemaforo(int id_semaforo, int valor){

	semctl(id_semaforo,0,SETVAL,valor);

}

void levantarSemaforo(int id_semaforo){

	struct sembuf operacion;
	/*printf("Levanta SEMAFORO \n");*/
	operacion.sem_num=0;
	operacion.sem_op = 1;
	operacion.sem_flg= 0;
	
	semop(id_semaforo,&operacion,1);

}


void esperarSemaforo(int id_semaforo){

	struct sembuf operacion;
	/*printf("Espera SEMAFORO \n");*/
	operacion.sem_num=0;
	operacion.sem_op = -1;
	operacion.sem_flg= 0;
	
	semop(id_semaforo,&operacion,1);

}



