#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "def_gen.h"
#include "gestiones.h"
#include "semaforo.h"







int main(int argc, char *argv[]){

	int opc, nro_panel;
	char linea[LARGO];
	char nueva_linea[LARGO];	
	char esc[LARGO];
	int id_semaforo;
 
	id_semaforo =  crearSemaforo();
	iniciarSemaforo(id_semaforo, VERDE);


	while(1){	
	
		printf("Opción 1: Leer Panel - Opción 2: Escribir Panel\n");
		scanf("%d", &opc);
	

		switch(opc){

			case 1:
			
				printf("Panel:\n");
				scanf("%d", &nro_panel);
				if(nro_panel > 3 || nro_panel < 1){
					printf("Ingrese una opción válida\n");
				}
				else{
					esperarSemaforo(id_semaforo);
					arc=abrirArchivo("paneles.txt","r");
					obtenerLineaArchivo(arc,&linea[0],sizeof(linea),nro_panel);
					printf("%s\n", &linea[0]);
					cerrarArchivo(arc);
					levantarSemaforo(id_semaforo);					
				}			
			
				break;

			case 2:
				printf("Panel:\n");
				scanf("%d", &nro_panel);
				if(nro_panel > 3 || nro_panel < 1){
					printf("Ingrese una opción válida\n");
				}
				else{
					printf("Escribe:\n");
					scanf("%s", &esc[0]);
					sprintf(&nueva_linea[0],"%s\n",&esc[0]);
					esperarSemaforo(id_semaforo);		
					reemplazarLineaArchivo(arc,&nueva_linea[0],nro_panel,"paneles.txt");
					levantarSemaforo(id_semaforo);					
				}			

				break;

			default:
				printf("Ingrese una opción válida\n");
					

		
			
		}	
	}

	return 0;

}
