#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/msg.h>
#include "definiciones.h"
#include "funciones.h"
#include "eventos.h"
#include "colas.h"
#include "global.h"

int main(int argc, char *argv[]){

	int n=0;
	int opc_julian;
	int opc_lautaro;
	int nro_jugador;

	int id_cola_mensajes;


	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

	printf("COMIENZA LA TANDA DE PENALES\n\n");
	srand(time(NULL));

	while(n<5){
		
		printf("PATEA JULIAN\n");
		getchar();
		nro_jugador=19;
		opc_julian=obtenerNumeroAleatorio(1,4);
		
		procesarEvento(id_cola_mensajes, opc_julian, nro_jugador);

		printf("PATEA LAUTARO\n");
		getchar();
		nro_jugador=10;
		opc_lautaro=obtenerNumeroAleatorio(1,4);

		procesarEvento(id_cola_mensajes, opc_lautaro, nro_jugador);

		n++;

	}

	printf("TERMINA EL PARTIDO\n");

	return 0;

}
