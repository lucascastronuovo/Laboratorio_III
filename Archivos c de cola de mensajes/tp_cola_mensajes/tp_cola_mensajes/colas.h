#ifndef _COLAS
#define _COLAS
 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <time.h>
#include <string.h>

#define CLAVE_BASE 33

#define LARGO_TMENSAJE 1024


typedef struct tipo_mensajes mensaje;
struct tipo_mensajes
{
	long	long_dest; 			
	int 	int_rte;			
	int 	int_evento;						
	char 	char_mensaje[LARGO_TMENSAJE];
};

int 	creo_id_cola_mensajes(int);
int 	borrar_mensajes(int);
int 	recibir_mensaje(int, long , mensaje*);
int 	enviar_mensaje(int, long, int, int, char*);

#endif

