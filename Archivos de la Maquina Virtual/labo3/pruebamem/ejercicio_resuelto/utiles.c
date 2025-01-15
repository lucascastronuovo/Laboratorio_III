#include <stdio.h>
#include "utiles.h"


struct tipo_inicial{

	int inicializado;

};

void limpiarPantalla(){

	int i=0;

	while(i<LINEAS_PANTALLA){
		printf("\n");
		i++;	
	}

}


void configurarMemoriaInicial(inicial* memoria){


	memoria[POS].inicializado=1;

}


void verificarMemoriaInicial(inicial* memoria){

	while(memoria[POS].inicializado==1){
		
		printf("¡¡¡No se ha ejecutado el programa que inicializa los semáforos!!! - Presione enter para continuar\n");
		getchar();
		
	}

	limpiarPantalla();

}
