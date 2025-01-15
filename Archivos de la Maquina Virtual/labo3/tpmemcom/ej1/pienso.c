#include <stdio.h>
#include <stdlib.h>
#include "semaforo.h"
#include "memcomp.h"
#include "funciones.h"
#include "def_gen.h"
#include "defmemsem.h"
#include "global.h"
#include "utiles.h"
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/shm.h>



int main(int argc, char *argv[]){


	
	char nombre_ganador[LARGO];		
	int local_pienso_un_numero;	
	int id_memoria;	
	int id_semaforo;
	int acierto=0;

	
	inicializado = (int*)creo_memoria(sizeof(int), &id_memoria, CLAVE_BASE);
	*inicializado=0;
	shmdt ((char *)inicializado);
	shmctl (id_memoria, IPC_RMID, (struct shmid_ds *)NULL);

	srand(time(NULL));
	local_pienso_un_numero = obtenerNumeroAleatorio(1,99);
	id_semaforo = crearSemaforo();
	iniciarSemaforo(id_semaforo, VERDE);
	memoria = (juego*)creo_memoria(sizeof(juego), &id_memoria, CLAVE_BASE);

	while(acierto==0){

		/*printf("Piensa un número\n");*/
		
		

		esperarSemaforo(id_semaforo);

		
		if(memoria->numero_pensado!=0 && memoria->estado_acierto==0){

			if(local_pienso_un_numero==memoria->numero_pensado){
				
				memoria->estado_acierto=1;
				strcpy(&nombre_ganador[0], &memoria->nombre_jugador[0]);
				acierto=1;

			}
			else{
				memoria->numero_pensado=0;
				
			}

		}
				
		levantarSemaforo(id_semaforo);
		usleep(1000);

	}
	printf("Nombre Ganador: %s\n", &nombre_ganador[0]);
/*	Terminada de usar la memoria compartida, la liberamos.*/
	
	shmdt ((char *)memoria);
	shmctl (id_memoria, IPC_RMID, (struct shmid_ds *)NULL);
	
	return 0;

}
