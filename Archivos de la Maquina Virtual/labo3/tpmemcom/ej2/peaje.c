#include <stdio.h>
#include <stdlib.h>
#include "semaforo.h"
#include "memcomp.h"
#include "funciones.h"
#include "gestiones.h"
#include "def_gen.h"
#include "defmemsem.h"
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/shm.h>



int main(int argc, char *argv[]){
	
	int id_memoria;
	int id_semaforo;
	via *memoria = 0;	
	int i;
	int N; 
	char cant_sobrepaso[LARGO];
	

	if(argc==2){
		
		M = atoi(argv[1]);
		
	}
	else{
		printf("No se ingresaron los parámetros correctamente\n");
	}
	
	id_semaforo = crearSemaforo();
	iniciarSemaforo(id_semaforo, VERDE);	

	memoria = (via*)creo_memoria(sizeof(via)*M, &id_memoria, CLAVE_BASE);

	srand(time(NULL));
	
	while(cant_sobrepaso_int<=100){
		printf("\n\n");
		for(i=1;i<=M;i++){
			esperarSemaforo(id_semaforo);
			if(memoria[i].vehiculos_en_cola>0 && memoria[i].vehiculos_en_cola<=10){

				memoria[i].vehiculos_en_cola=	memoria[i].vehiculos_en_cola -1;


			}
			else{
				memoria[i].vehiculos_en_cola=0;
				cant_sobrepaso_int++;
				snprintf(&cant_sobrepaso[0],sizeof(cant_sobrepaso),"%d\n",cant_sobrepaso_int);
				arc=abrirArchivo("sobrepaso.txt","w");
				escribirArchivo(arc, &cant_sobrepaso[0]);
				cerrarArchivo(arc);
				

			}
			levantarSemaforo(id_semaforo);
			N=obtenerNumeroAleatorio(100,5000);

			usleep(N);

		}


		for(i=1;i<=M;i++){
			esperarSemaforo(id_semaforo);
			printf("VIA[%d]:    %d Vehículos\n",i ,memoria[i].vehiculos_en_cola);
			levantarSemaforo(id_semaforo);

		}

		
		sleep(1);
	}
	shmdt ((char *)memoria);
	shmctl (id_memoria, IPC_RMID, (struct shmid_ds *)NULL);
	return 0;
}


