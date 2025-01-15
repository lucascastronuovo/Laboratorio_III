#include <stdio.h>
#include <stdlib.h>
#include "gestiones.h"
#include "gestiones_fun.h"
#include "semaforo.h"
#include "defprac.h"
#include <unistd.h>
#include <string.h>



int main(int argc, char *argv[]){
	
	char linea[LARGO];
	char linea2[LARGO];
	int id_semaforo;
	int cont=0;

	

	id_semaforo =  crearSemaforo();
	iniciarSemaforo(id_semaforo, VERDE);
	
	
	reemplazarLineaArchivo(arc,"Boca hoy tiene que ganar\n",4,"pedido.txt");

	while(1){
		esperarSemaforo(id_semaforo);
		/*
		arc=abrirArchivo("pedido.txt","r");
		
		if(arc==0x00){
			printf("No se puede abrir\n");		
		}
		else{
			memset(&linea[0],0x00,sizeof(linea));
			memset(&linea2[0],0x00,sizeof(linea2));			
			cont++;	
			obtenerUltimaLineaArchivo(&linea[0],sizeof(linea));
			obtenerLineaArchivo(&linea2[0],sizeof(linea2), cont);*/
		ultimaLinea("pedido.txt","r",&linea[0]);
			
		printf("%s\n",&linea[0]);
			/*printf("%s\n",&linea2[0]);
			cerrarArchivo(arc);	
			
		}	*/
		levantarSemaforo(id_semaforo);
		sleep(4);

	}
	


	return 0;

}
