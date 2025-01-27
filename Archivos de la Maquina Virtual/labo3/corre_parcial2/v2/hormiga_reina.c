#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <unistd.h>
#include "memcomp.h"
#include "definiciones.h"
#include "clave.h"
#include "semaforo.h"
#include "utiles.h"
#include "colas.h"
#include "global.h"
#include "menu.h"

int main(int argc, char *argv[]){


	int id_semaforo, id_cola_mensajes, id_insumos, id_estados, id_memoria;
	int cant_hormigas, opc, i, n_hormiga;
	
	id_semaforo =  crearSemaforo();
	iniciarSemaforo(id_semaforo, VERDE);
	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

	inicializado = (int*)creo_memoria(sizeof(int), &id_memoria, CLAVE_BASE);
	configurarMemoriaInicial(inicializado);
	*inicializado=0;
	shmdt ((char *)inicializado);
	shmctl (id_memoria, IPC_RMID, (struct shmid_ds *)NULL);


	m_insumos=(insumos*)creo_memoria(sizeof(insumos) * (CANT_INSUMOS + 1),&id_insumos,CLAVE_BASE);
	m_estados=(estados*)creo_memoria(sizeof(estados)*2,&id_estados,CLAVE_BASE+1);
	
	

	limpiarPantalla();

	printf("Elige 4 insumos a juntar:\n\n");

	for(i=0;i<CANT_INSUMOS;i++){
		limpiarPantalla();
		printf("Juntar:\n");
		esperarSemaforo(id_semaforo);
		scanf("%s", &m_insumos[i].descripcion[0]);
		m_insumos[i].cant_insumo=0;
		levantarSemaforo(id_semaforo);
		usleep(1000);
	}

	for(i=0;i<CANT_INSUMOS;i++){
		printf("Nro insumo: %d - Descripcion: %s\n", i,&m_insumos[i].descripcion[0]);
		

	}
	limpiarPantalla();
	esperarSemaforo(id_semaforo);
	cant_hormigas= m_estados->cant_hormigas;
	levantarSemaforo(id_semaforo);
	usleep(1000);
	printf("Cantidad de hormigas: %d\n", cant_hormigas);
	usleep(10000);
	limpiarPantalla();
	borrar_mensajes(id_cola_mensajes);

	
	opc=menu(cant_hormigas, &n_hormiga);


	while(m_estados->done==0){

		switch(opc){


			case 1:
				enviar_mensaje(id_cola_mensajes,MSG_HORMIGAS+n_hormiga,MSG_REINA,EVT_JUNTAR_1,"INSUMO 1");
				break;
			case 2:
				enviar_mensaje(id_cola_mensajes,MSG_HORMIGAS+n_hormiga,MSG_REINA,EVT_JUNTAR_2,"INSUMO 2");
				break;
			case 3:
				enviar_mensaje(id_cola_mensajes,MSG_HORMIGAS+n_hormiga,MSG_REINA,EVT_JUNTAR_3,"INSUMO 3");
				break;
			case 4:
				enviar_mensaje(id_cola_mensajes,MSG_HORMIGAS+n_hormiga,MSG_REINA,EVT_JUNTAR_4,"INSUMO 4");
				break;
			default:
				printf("Ingrese una opción válida\n");


		}

		usleep(10000);
		limpiarPantalla();

		opc=menu(cant_hormigas, &n_hormiga);
	


	}
	
	m_estados->done=1;
		

	shmdt((char *)m_insumos);
	shmctl(id_insumos,IPC_RMID,(struct shmid_ds *)NULL);	
	shmdt((char *)m_estados);
	shmctl(id_estados,IPC_RMID,(struct shmid_ds *)NULL);	
	msgctl (id_cola_mensajes, IPC_RMID, (struct msqid_ds *)NULL);

	return 0;

}
