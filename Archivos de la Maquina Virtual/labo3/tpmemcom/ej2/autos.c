#include <stdio.h>
#include <stdlib.h>
#include "semaforo.h"
#include "memcomp.h"
#include "funciones.h"
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
	int menor=0;
	int menor_i=0;

	if(argc==2){
		
		M = atoi(argv[1]);
		
	}
	else{
		printf("No se ingresaron los parámetros correctamente\n");
	}
	
	id_semaforo = crearSemaforo();


	memoria = (via*)creo_memoria(sizeof(via)*M, &id_memoria, CLAVE_BASE);

	srand(time(NULL));

	while(cant_sobrepaso_int<=100){
		esperarSemaforo(id_semaforo);
		for(i=1;i<=M;i++){

			if(i==1){

				menor=memoria[i].vehiculos_en_cola;
				menor_i=i;
			}
			else if(menor>memoria[i].vehiculos_en_cola){
				menor=memoria[i].vehiculos_en_cola;
				menor_i=i;
			}


		}


		memoria[menor_i].vehiculos_en_cola=memoria[menor_i].vehiculos_en_cola +1;
		levantarSemaforo(id_semaforo);
		printf("Menos vehículos en vía %d\n", menor_i);
		N=obtenerNumeroAleatorio(400,600);

		usleep(N);
		
	}

	return 0;

}
