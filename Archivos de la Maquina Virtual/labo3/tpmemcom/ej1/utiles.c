#include <stdio.h>
#include "utiles.h"




void limpiarPantalla(){

	int i=0;

	while(i<LINEAS_PANTALLA){
		printf("\n");
		i++;	
	}

}


void configurarMemoriaInicial(int* inicializado){


	*inicializado=1;

}


void verificarMemoriaInicial(int* inicializado){

	while(*inicializado==1){
		
		printf("¡¡¡No se ha ejecutado el programa que inicializa los semáforos!!! - Presione enter para continuar\n");
		getchar();
		
	}

	limpiarPantalla();

}