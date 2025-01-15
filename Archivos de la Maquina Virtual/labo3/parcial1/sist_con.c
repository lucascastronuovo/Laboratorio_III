#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "def_gen.h"
#include "gestiones.h"
#include "semaforo.h"







int main(int argc, char *argv[]){
	
	int nro_sistema;
	char cant_ord[LARGO];
	char precio_total[LARGO];
	int id_semaforo;
 
	id_semaforo =  crearSemaforo();

	if(argc==2){
		
		nro_sistema = atoi(argv[1]);


		if(nro_sistema > 3 || nro_sistema < 1){

			printf("Parámetro ingresado no válido\n");
		
		}
		else{
			while(1){
				memset(&cant_ord[0],0x00,sizeof(cant_ord));
				memset(&precio_total[0],0x00,sizeof(precio_total));

				if(nro_sistema==1){
					
					esperarSemaforo(id_semaforo);				
					arc=abrirArchivo("ordenes.txt","r");
					obtenerLineaArchivo(arc,&cant_ord[0],sizeof(cant_ord),2);
					cerrarArchivo(arc);
					arc=abrirArchivo("ordenes.txt", "r");
					obtenerLineaArchivo(arc,&precio_total[0],sizeof(precio_total),3);
					cerrarArchivo(arc);
					levantarSemaforo(id_semaforo);


				}
				else if(nro_sistema==2){
					esperarSemaforo(id_semaforo);				
					arc=abrirArchivo("ordenes.txt","r");
					obtenerLineaArchivo(arc,&cant_ord[0],sizeof(cant_ord),7);
					cerrarArchivo(arc);
					arc=abrirArchivo("ordenes.txt", "r");
					obtenerLineaArchivo(arc,&precio_total[0],sizeof(precio_total),8);
					cerrarArchivo(arc);
					levantarSemaforo(id_semaforo);

				}
				else if(nro_sistema==3){

					esperarSemaforo(id_semaforo);				
					arc=abrirArchivo("ordenes.txt","r");
					obtenerLineaArchivo(arc,&cant_ord[0],sizeof(cant_ord),12);
					cerrarArchivo(arc);
					arc=abrirArchivo("ordenes.txt", "r");
					obtenerLineaArchivo(arc,&precio_total[0],sizeof(precio_total),13);
					cerrarArchivo(arc);
					levantarSemaforo(id_semaforo);

				}
				printf("Cantidad: %s", &cant_ord[0]);
				printf("Precio: %s", &precio_total[0]);

				usleep(100000);

				

			}



		}
		
		
	}
	else{
		printf("No se ingresaron paramentros\n");	
	}

	return 0;


}
