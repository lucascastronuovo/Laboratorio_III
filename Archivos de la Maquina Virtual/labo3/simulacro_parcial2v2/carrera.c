#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include "definiciones.h"
#include "colas.h"
#include "global.h"
#include "memcomp.h"


int main(int argc, char *argv[]){

	int id_cola_mensajes;
	int nro_jugador;
	int id_memoria;
	int done=0;
	int pasos_conejo=0;
	int pasos_tortuga=0;
	int ya_descanse=0;	
	
	memoria = (inicializado*)creo_memoria(sizeof(inicializado)*CANT_JUGADORES, &id_memoria, CLAVE_BASE);
	memoria[1].ini=0;
	verificarMemoriaInicial(&memoria[1].ini);
	shmdt ((char *)memoria);
	shmctl (id_memoria, IPC_RMID, (struct shmid_ds *)0);
	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
	borrar_mensajes(id_cola_mensajes);
	
	while(done==0){

		recibir_mensaje(id_cola_mensajes,MSG_CARRERA,&msg);

		switch(msg.int_evento){

			case(EVT_PASOS_CONEJO):
				pasos_conejo+= atoi(msg.char_mensaje);
				
				if(pasos_conejo >= 50 && ya_descanse==0){
					printf("El conejo descansa: %d pasos\n", pasos_conejo);
					ya_descanse=1;
					enviar_mensaje(id_cola_mensajes,MSG_JUGADOR+0,MSG_CARRERA,EVT_DESCANSO,"Descanso");
				
				}
				else if(pasos_conejo>=100){
					printf("Ganó el conejo: %d pasos\n", pasos_conejo);
					enviar_mensaje(id_cola_mensajes,MSG_JUGADOR+0,MSG_CARRERA,EVT_FINALIZADO,"Ganó el conejo");					
					enviar_mensaje(id_cola_mensajes,MSG_JUGADOR+1,MSG_CARRERA,EVT_FINALIZADO,"Ganó el conejo");					
					done=1;
				}
				else{
					printf("El conejo avanza: %d pasos\n", pasos_conejo);
					enviar_mensaje(id_cola_mensajes,MSG_JUGADOR+0,MSG_CARRERA,EVT_RTA_PASOS_CONEJO,msg.char_mensaje);					
				}
				break;

			case(EVT_PASOS_TORTUGA):
				pasos_tortuga+= atoi(msg.char_mensaje);
				
				if(pasos_tortuga>=100){
					printf("Ganó la tortuga: %d pasos\n", pasos_tortuga);
					enviar_mensaje(id_cola_mensajes,MSG_JUGADOR+1,MSG_CARRERA,EVT_FINALIZADO,"Ganó la tortuga");					
					enviar_mensaje(id_cola_mensajes,MSG_JUGADOR+0,MSG_CARRERA,EVT_FINALIZADO,"Ganó la tortuga");					
					done=1;

				}
				else{
					printf("La tortuga avanza: %d pasos\n", pasos_tortuga);
					enviar_mensaje(id_cola_mensajes,MSG_JUGADOR+1,MSG_CARRERA,EVT_RTA_PASOS_TORTUGA,msg.char_mensaje);					
				}
				break;
			default:
				printf("Evento sin definir\n");
				break;
		
			

		}

	}
	
	printf("Done %d", done);	
	return 0;


}
