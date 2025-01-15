#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#include "memcomp.h"
#include "definiciones.h"
#include "colas.h"
#include "global.h"
#include "clave.h"
#include "semaforo.h"
#include "funciones.h"
#include "utiles.h"
#include "threads.h"


void *funcionThread(void *parametro){
	
	hormigas *hilo = (hormigas *)parametro;
	
	int nro_hormiga, id_cola_mensajes, id_semaforo;
	int evento, cantidad, id_estados, id_insumos;
	int n;
	int cant_hormigas;
	char contenido[LARGO];

	insumos *m_insumos=NULL;
	estados *m_estados=NULL;
	
	

	m_insumos=(insumos*)creo_memoria(sizeof(insumos) * (CANT_INSUMOS + 1),&id_insumos,CLAVE_BASE);
	m_estados=(estados*)creo_memoria(sizeof(estados)*2,&id_estados,CLAVE_BASE+1);
	
	pthread_mutex_init(&mutex,0);
	nro_hormiga = hilo->nro_hormiga;
	id_cola_mensajes = hilo->id_cola_mensajes;
	id_semaforo = hilo->id_semaforo;

	esperarSemaforo(id_semaforo);
	cant_hormigas = m_estados->cant_hormigas;
	m_estados->done=0;
	levantarSemaforo(id_semaforo);
	usleep(1000);

	srand(time(NULL));

	n=obtenerNumeroAleatorio(10,500);
	


	while(m_estados->done==0){
		
		

		pthread_mutex_lock(&mutex);
		recibir_mensaje(id_cola_mensajes,MSG_HORMIGAS+nro_hormiga,&msg);
		printf("Recibí el mensaje y soy la hormiga %d\n", nro_hormiga);

		usleep(1000*n);


		memset(&contenido[0], 0x00, sizeof(contenido));
		strcpy(&contenido[0], &msg.char_mensaje[0]);
		evento = msg.int_evento;
		cantidad = obtenerNumeroAleatorio(1,4);
		
		switch(evento){

			case EVT_JUNTAR_1:


				esperarSemaforo(id_semaforo);
				m_insumos[0].cant_insumo+=cantidad;
				printf("Cantidad de %s: %d\n", &m_insumos[0].descripcion[0], m_insumos[0].cant_insumo);
				levantarSemaforo(id_semaforo);



				break;

			case EVT_JUNTAR_2:


				esperarSemaforo(id_semaforo);
				m_insumos[1].cant_insumo+=cantidad;
				printf("Cantidad de %s: %d\n", &m_insumos[1].descripcion[0], m_insumos[1].cant_insumo);
				levantarSemaforo(id_semaforo);



				break;

			case EVT_JUNTAR_3:


				esperarSemaforo(id_semaforo);
				m_insumos[2].cant_insumo+=cantidad;
				printf("Cantidad de %s: %d\n", &m_insumos[2].descripcion[0], m_insumos[2].cant_insumo);
				levantarSemaforo(id_semaforo);



				break;

			case EVT_JUNTAR_4:


				esperarSemaforo(id_semaforo);
				m_insumos[3].cant_insumo+=cantidad;
				printf("Cantidad de %s: %d\n", &m_insumos[3].descripcion[0], m_insumos[3].cant_insumo);
				levantarSemaforo(id_semaforo);



				break;
			
			default:
				break;

		}

		if(m_insumos[0].cant_insumo >=10 || m_insumos[1].cant_insumo >=10 || m_insumos[2].cant_insumo >=10 || m_insumos[3].cant_insumo >=10){
			
			esperarSemaforo(id_semaforo);
			m_estados->done=1;
			levantarSemaforo(id_semaforo);
			usleep(1000);

		}
		pthread_mutex_unlock(&mutex);		
		
		
		usleep(1000000);

		limpiarPantalla();
			
	}

	
	

	shmdt((char *)m_insumos);
	shmctl(id_insumos,IPC_RMID,(struct shmid_ds *)NULL);	
	shmdt((char *)m_estados);
	shmctl(id_estados,IPC_RMID,(struct shmid_ds *)NULL);	
	pthread_exit(NULL);
}

