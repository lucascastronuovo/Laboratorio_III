#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include "memcomp.h"
#include "definiciones.h"
#include "clave.h"
#include "semaforo.h"


int main(int argc, char *argv[]){


	int id_semaforo, id_cola_mensajes, id_insumos, id_estados;
	int cant_hormigas, opc, i;
	insumos *m_insumos=NULL;
	estados *m_estados=NULL;	
	id_semaforo =  crearSemaforo();
	

	m_insumos=(insumos*)creo_memoria(sizeof(insumos) * (CANT_INSUMOS + 1),&id_insumos,CLAVE_BASE);
	m_estados=(estados*)creo_memoria(sizeof(estados)*2,&id_estados,CLAVE_BASE+1);


	if (argc == 2){
	
		cant_hormigas=atoi(argv[1]);
		if(cant_hormigas<=0){
			printf("Cantidad de hormigas ingresada no válida\n");
			return 0;
		}


	}
	else{

			printf("Ingrese una cantidad\n");
			return 0;
	

	}

	esperarSemaforo(id_semaforo);
	m_estados->cant_hormigas = cant_hormigas;
	levantarSemaforo(id_semaforo);
	usleep(1000);

	sleep(20);


	shmdt((char *)m_insumos);

	shmdt((char *)m_estados);

	return 0;

}
