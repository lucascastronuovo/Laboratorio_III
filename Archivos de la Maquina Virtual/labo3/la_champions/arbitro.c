#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <unistd.h>
#include "definiciones.h"
#include "semaforo.h"
#include "funciones.h"
#include "eventos.h"
#include "colas.h"
#include "global.h"
#include "utiles.h"

int main(int argc, char *argv[]){

	int n=0;

	int opc_julian;
	int opc_lautaro;
	int goles_lautaro=0;
	int goles_julian=0;
	
	int id_cola_mensajes;
	int id_semaforo;
	



	id_semaforo =  crearSemaforo();
	iniciarSemaforo(id_semaforo, VERDE);	
	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

	borrar_mensajes(id_cola_mensajes);

	printf("COMIENZA LA TANDA DE PENALES\n\n");
	sleep(2);
	limpiarPantalla();
	srand(time(NULL));

	while(n<5 || goles_julian == goles_lautaro){
		
		printf("PATEA JULIAN\n");
		getchar();
		limpiarPantalla();
		opc_julian=obtenerNumeroAleatorio(1,4);

		procesarEvento(id_cola_mensajes, opc_julian, NRO_JULIAN);
		
		esperarSemaforo(id_semaforo);
		recibir_mensaje(id_cola_mensajes,MSG_ARBITRO,&msg);
		
		switch(msg.int_evento){
			
			case EVT_GOL_JULIAN:
				goles_julian=atoi(msg.char_mensaje);
				break;
			case EVT_GOL_LAUTARO:
				goles_lautaro=atoi(msg.char_mensaje);
			case EVT_NO_GOLES:
				break;
			default:
				break;
		}
	
		
		levantarSemaforo(id_semaforo);
		usleep(10000);

		printf("PATEA LAUTARO\n");
		getchar();
		limpiarPantalla();
		opc_lautaro=obtenerNumeroAleatorio(1,4);

		procesarEvento(id_cola_mensajes, opc_lautaro, NRO_LAUTARO);	
			
		
		esperarSemaforo(id_semaforo);
		recibir_mensaje(id_cola_mensajes,MSG_ARBITRO,&msg);
		
		switch(msg.int_evento){
			
			case EVT_GOL_JULIAN:
				goles_julian=atoi(msg.char_mensaje);
				break;
			case EVT_GOL_LAUTARO:
				goles_lautaro=atoi(msg.char_mensaje);
			case EVT_NO_GOLES:
				break;
			default:
				break;
		}
	
		
		levantarSemaforo(id_semaforo);
		usleep(10000);
		
		printf("JULIÁN: %d --- LAUTARO: %d\n\n", goles_julian,goles_lautaro);
		sleep(2);
		limpiarPantalla();		
		n++;

	}
	
	
	
	
	printf("TERMINA EL PARTIDO\n");
	sleep(3);
	limpiarPantalla();	
	
	if(goles_julian > goles_lautaro){
		printf("¡¡¡¡GANOOOOO JULIÁN!!!!\n");
		printf("JULIÁN: %d --- LAUTARO: %d\n\n", goles_julian,goles_lautaro);
	}
	else{
		printf("¡¡¡¡GANOOOOO LAUTARO!!!!\n");
		printf("JULIÁN: %d --- LAUTARO: %d\n\n", goles_julian,goles_lautaro);
	}
	
	return 0;

}
