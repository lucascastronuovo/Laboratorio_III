#include <stdio.h>
#include <stdlib.h>
#include "semaforo.h"
#include "memcomp.h"
#include "funciones.h"
#include "def_gen.h"
#include "defmemsem.h"
#include "utiles.h"
#include "global.h"
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/shm.h>








int main(int argc, char *argv[]){
	
	

	char nombre_jugador[LARGO];
	int id_memoria;	
	int id_semaforo;
	int n,m,i,stop,num;
	int vec[50];
	int cant_intentos=0;
	int acierto=0;
	
	inicializado = (int*)creo_memoria(sizeof(int), &id_memoria, CLAVE_BASE);
	configurarMemoriaInicial(inicializado);
	
	verificarMemoriaInicial(inicializado);
	shmdt ((char *)inicializado);

	srand(time(NULL));
	memoria = (juego*)creo_memoria(sizeof(juego), &id_memoria, CLAVE_BASE);
	id_semaforo = crearSemaforo();
	
	
	


	


	m=1;
	n=0;	
	
	printf("Nombre jugador\n");
	scanf("%s",&nombre_jugador[0]);

	while(acierto==0){
			

		esperarSemaforo(id_semaforo);
	
		strcpy(&memoria->nombre_jugador[0], &nombre_jugador[0]);


		/*printf("%s\n", &memoria[1].nombre_jugador[0]);*/


		if(memoria->numero_pensado==0 && memoria->estado_acierto==0){



			memoria->numero_pensado = obtenerNumeroAleatorio(1,99);;
			
		

		}

		else if(memoria->numero_pensado!=0 && memoria->estado_acierto==1){

			
			printf("Cantidad de Intentos: %d\n", cant_intentos);
			acierto=1;
		}
		cant_intentos++;
		levantarSemaforo(id_semaforo);
		usleep(2000);
	}
/*	Terminada de usar la memoria compartida, la liberamos.*/
	
	shmdt ((char *)memoria);



	return 0;

}
