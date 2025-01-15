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
	int i;
	int opc_julian;
	int opc_lautaro;


	int id_cola_mensajes;
	

	

	
	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);

	borrar_mensajes(id_cola_mensajes);

	printf("COMIENZA LA TANDA DE PENALES\n\n");
	srand(time(NULL));

	while(n<5){
		
		printf("PATEA JULIAN\n");
		getchar();

		opc_julian=obtenerNumeroAleatorio(1,4);
		
		procesarEvento(id_cola_mensajes, opc_julian, NRO_JULIAN);
		
		printf("PATEA LAUTARO\n");
		getchar();

		opc_lautaro=obtenerNumeroAleatorio(1,4);

		procesarEvento(id_cola_mensajes, opc_lautaro, NRO_LAUTARO);

		n++;

	}
	

	
	printf("TERMINA EL PARTIDO\n");
	


	return 0;

}
