#include <stdio.h>
#include "utiles.h"




void limpiarPantalla(){

	int i=0;

	while(i<LINEAS_PANTALLA){
		printf("\n");
		i++;	
	}

}


void configurarMemoriaInicial(int *ini){

	

	*ini =1;
	printf("%d",*ini);
}


void verificarMemoriaInicial(int *ini){

	int i;
	
	while(*ini==1){
	
		printf("¡¡¡No se ha ejecutado el programa que inicializa los semáforos!!! - Presione enter para continuar\n");
		getchar();
	
	}
	
	limpiarPantalla();

}
