#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "gestiones.h"
#include "semaforo.h"
#include "defprac.h"
#include "defsem.h"
#include <unistd.h>
#include <string.h>
#include <time.h>



int main(int argc, char *argv[]){
	
	int a;
	char lec[LARGO];
	int id_semaforo;

	id_semaforo =  crearSemaforo();
	

	while(1){
		esperarSemaforo(id_semaforo);
		a=abrirArchivo("pedido.txt","r");
		
		if(a==0){
			printf("No se puede abrir\n");		
		}
		else if(a==1){
			
			while(!feof(arc)){

				memset(&lec[0],0x00,sizeof(lec));
				leerArchivoConEspacios(&lec[0], sizeof(lec));
				printf("%s",&lec[0]);
				
							
			}
			

			cerrarArchivo();
		}
		
		levantarSemaforo(id_semaforo);
		sleep(4);

	}
	


	return 0;

}
