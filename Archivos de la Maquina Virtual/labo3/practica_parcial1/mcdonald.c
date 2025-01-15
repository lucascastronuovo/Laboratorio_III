#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "gestiones.h"
#include "gestiones_fun.h"
#include "semaforo.h"
#include "defprac.h"
#include <unistd.h>
#include <string.h>
#include <time.h>


int main(int argc, char *argv[]){
	
	int nro_pedido;
	char esc[LARGO];
	int id_semaforo;
	
	
	
	id_semaforo =  crearSemaforo();
	

	while(1){
		esperarSemaforo(id_semaforo);
		

		
		srand(time(NULL));

		memset(&esc[0],0x00,sizeof(esc));
		nro_pedido=obtenerNumeroAleatorio(1,50);

		snprintf(&esc[0],sizeof(esc),"Nro pedido: %d\n",nro_pedido);
		escribir("pedido.txt", "a", &esc[0]);
		/*arc=abrirArchivo("pedido.txt","a");
		
		if(arc==0x00){
			printf("No se puede abrir\n");
					
		}
		else{

			memset(&esc[0],0x00,sizeof(esc));
			nro_pedido=obtenerNumeroAleatorio(1,50);

			snprintf(&esc[0],sizeof(esc),"Nro pedido: %d\n",nro_pedido);
			escribirArchivo(arc,&esc[0]);
			
			cerrarArchivo(arc);
									
			
											
		}
		

		printf("escritura\n");*/
		levantarSemaforo(id_semaforo);
		sleep(4);
		
	
	}


	return 0;

}



