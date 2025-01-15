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

void *funcionThread(void *parametro){
	
	hormigas *hilo = (hormigas *)parametro;
	
	int nro_hormiga, id_cola_mensajes, id_semaforo;
	int evento, cantidad, id_estados, id_insumos;
	int n, i;
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
		
		printf("HORMIGA %d \n\n", nro_hormiga);

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

		if(m_insumos[0].cant_insumo >=90 || m_insumos[1].cant_insumo >=90 || m_insumos[2].cant_insumo >=90 || m_insumos[3].cant_insumo >=90){
			
			esperarSemaforo(id_semaforo);
			m_estados->done=1;
			levantarSemaforo(id_semaforo);
			usleep(1000);

		}
		pthread_mutex_unlock(&mutex);		
		
		
		usleep(100*n);

		
			
	}


	

	shmdt((char *)m_insumos);
	shmctl(id_insumos,IPC_RMID,(struct shmid_ds *)NULL);	
	shmdt((char *)m_estados);
	shmctl(id_estados,IPC_RMID,(struct shmid_ds *)NULL);	
	pthread_exit(NULL);
}



int main(int argc, char *argv[]){


	int id_semaforo, id_cola_mensajes, id_insumos, id_estados;
	int cant_hormigas, opc, i;
	insumos *m_insumos=NULL;
	estados *m_estados=NULL;	
	hormigas *h_hormigas;
	pthread_t *idHilo;
	pthread_attr_t attr;
		
	
	
	id_semaforo =  crearSemaforo();
	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

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

	idHilo=(pthread_t *)malloc(sizeof(pthread_t)*(cant_hormigas+1));
	h_hormigas=(hormigas *)malloc(sizeof(hormigas)*(cant_hormigas+1));
	

	esperarSemaforo(id_semaforo);
	m_estados->cant_hormigas = cant_hormigas;
	levantarSemaforo(id_semaforo);
	usleep(1000);


	

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

	borrar_mensajes(id_cola_mensajes);

	for(i=0;i<cant_hormigas;i++){
		h_hormigas[i].nro_hormiga= i+1;
		h_hormigas[i].id_cola_mensajes = id_cola_mensajes;
		h_hormigas[i].id_semaforo = id_semaforo;
		pthread_create(&idHilo[i],&attr,funcionThread,&h_hormigas[i]);
	}

	for(i=0;i<cant_hormigas;i++){
		pthread_join(idHilo[i],NULL);
	}

	free(idHilo);
	free(h_hormigas);
	
	shmdt((char *)m_insumos);

	shmdt((char *)m_estados);

	return 0;

}
