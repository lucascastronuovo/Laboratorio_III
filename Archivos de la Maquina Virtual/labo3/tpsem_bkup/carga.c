#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "gestiones.h"
#include "funciones.h"
#include "semaforo.h"
#include "defsem.h"


int main(int argc, char *argv[]){

	int vuelo;
	char destino[20 +1];
	int cantpas;

	char esc[50 + 1];

	int id_semaforo = crearSemaforo();
	
	int a;


	srand(time(NULL));


	vuelo = obtenerNumeroAleatorio(0,11);		

	
	while(vuelo != 0){
		
		memset(&destino[0],0x00,sizeof(destino));
		memset(&esc[0],0x00,sizeof(esc));
	
		
		
		if(vuelo == 1){
			strcpy(&destino[0], "CABA");
		}
		
		else if(vuelo == 2){
			strcpy(&destino[0], "WASHINGTON D. C.");
		}
		else if(vuelo == 3){
			strcpy(&destino[0], "TOKIO");
		}
		else if(vuelo == 4){
			strcpy(&destino[0], "PARÍS");
		}
		else if(vuelo == 5){
			strcpy(&destino[0], "LONDRES");
		}
		else if(vuelo == 6){
			strcpy(&destino[0], "MADRID");
		}
		else if(vuelo == 7){
			strcpy(&destino[0], "BERLÍN");
		}
		else if(vuelo == 8){
			strcpy(&destino[0], "VIENA");
		}
		else if(vuelo == 9){
			strcpy(&destino[0], "BRASILIA");
		}
		else if(vuelo == 10){
			strcpy(&destino[0], "MONTEVIDEO");
		}
		else if(vuelo == 11){
			strcpy(&destino[0], "DOHA");
		}
		
		cantpas = obtenerNumeroAleatorio(1,CAPACIDAD);

		
		
		esperarSemaforo(id_semaforo);
		/*Sección Crítica*/
		a=abrirArchivo(NOMARCH, "a");
		if(a==0){
			printf("No se puede Abrir\n");
		}
		else if(a==1){
			snprintf(&esc[0],sizeof(esc),"10%02d\t%s\t%d\n",vuelo -1, &destino[0], cantpas);
			escribirArchivo(&esc[0]);
			cerrarArchivo();
		}
		/*Sección Crítica*/
		levantarSemaforo(id_semaforo);
		
		vuelo = obtenerNumeroAleatorio(0,11);
	


	}



	return 0;

}


