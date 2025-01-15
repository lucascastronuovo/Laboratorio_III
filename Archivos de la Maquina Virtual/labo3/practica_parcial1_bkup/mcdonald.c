#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "gestiones.h"
#include "semaforo.h"
#include "defprac.h"
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "defsem.h"

int main(int argc, char *argv[]){
	
	int a, nro_pedido;
	char esc[LARGO];
	int id_semaforo;
	
	id_semaforo =  crearSemaforo();
	iniciarSemaforo(id_semaforo, VERDE);
	
	while(1){
		esperarSemaforo(id_semaforo);
		a=abrirArchivo("pedido.txt","a");
		
		if(a==0){
			printf("No se puede abrir\n");
					
		}
		else if(a==1){

			memset(&esc[0],0x00,sizeof(esc));
			nro_pedido=obtenerNumeroAleatorio(1,50);

			snprintf(&esc[0],sizeof(esc),"Nro pedido: %d\n",nro_pedido);
			escribirArchivo(&esc[0]);
			
			cerrarArchivo();
									
			
											
		}

		/*printf("escritura\n");*/
		levantarSemaforo(id_semaforo);
		sleep(4);
		
	
	}


	return 0;

}




