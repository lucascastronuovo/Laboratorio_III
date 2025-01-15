#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestiones.h"
#include "semaforo.h"
#include "defsim.h"
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

typedef struct paneles{
			
		int nro_panel;
		char mensaje[LARGO_MENSAJE];	

	};


int main(int argc, char *argv[]){
	
	int a;
	int id_semaforo = crearSemaforo();
	char lec[20+1];	
	
	struct paneles panel;

	iniciarSemaforo(id_semaforo, VERDE);	

	
	
	if(argc==2){
		
		panel.nro_panel= atoi(argv[1]);
		while(1){
			esperarSemaforo(id_semaforo);	
			if(panel.nro_panel==1){		
		
				a=abrirArchivo("panel1.txt", "w");
				if(a==0){
		
					printf("No se puede Abrir\n");
				}
				else if(a==1){
					memset(&panel.mensaje[0],0x00,sizeof(panel.mensaje));
					snprintf(&panel.mensaje[0],sizeof(panel.mensaje),"default");
					escribirArchivo(&panel.mensaje[0]);
						
					cerrarArchivo();
				}		
			}
			else if(panel.nro_panel==2){
				a=abrirArchivo("panel2.txt", "w");
				if(a==0){
		
					printf("No se puede Abrir\n");
				}
				else if(a==1){
					memset(&panel.mensaje[0],0x00,sizeof(panel.mensaje));
					snprintf(&panel.mensaje[0],sizeof(panel.mensaje),"default");
					escribirArchivo(&panel.mensaje[0]);
						
					cerrarArchivo();
				}
			}
			else if(panel.nro_panel==3){
				a=abrirArchivo("panel3.txt", "w");
				if(a==0){
		
					printf("No se puede Abrir\n");
				}
				else if(a==1){
					memset(&panel.mensaje[0],0x00,sizeof(panel.mensaje));
					snprintf(&panel.mensaje[0],sizeof(panel.mensaje),"default");
					escribirArchivo(&panel.mensaje[0]);
						
					cerrarArchivo();
				}
			}
			else{
				printf("No se pudo hacer la escritura\n");		
			}
			
			
			esperarSemaforo(id_semaforo);
			leerArchivo(&lec[0]);
			if(strcmp(&panel.mensaje[0],&lec[0])==1){
				printf("%s\n",&lec[0]);
			}
			levantarSemaforo(id_semaforo);
		}	usleep(INTERVALO_CHEQUEO);
	}
	else{
	
		printf("Error: Se han ingresados más parámetros que los permitidos\n");

	}

	
				
	
		
	
	return 0;

}
