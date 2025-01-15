#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "semaforo.h"
#include "defsem.h"
#include <string.h>
#include "gestiones.h"

#include <sys/ipc.h>
#include <sys/sem.h>

int main(int argc, char *argv[]){


	int i=0;
	char lec[20 + 1];
	char nn[20 + 1];
	
	

	int id_semaforo = crearSemaforo();

	int a;

	iniciarSemaforo(id_semaforo, VERDE);
	
	while(1){

		esperarSemaforo(id_semaforo);
		
		/*Sección Crítica*/

		do{	
			memset(&lec[0],0x00,sizeof(lec));

			a=abrirArchivo(NOMARCH, "r+");			

			if(a==0){
		
				printf("No se puede Abrir\n");
			}
			else if(a==1){
				

				while(!feof(arc)){
						
					memset(&lec[0],0x00,sizeof(lec));
					leerArchivo(&lec[0]);
					/*usleep(500000);*/
					printf("%s\n", &lec[0]);
					
					
																		
				}
		
				cerrarArchivo();
				
			
			}
		
		
			

			if(&lec[0] == 0x00){

				memset(&nn[0],0x00,sizeof(nn));
				snprintf(&nn[0],sizeof(nn), NU_NOMARCH,i);
				renombrarArchivo(NOMARCH, &nn[0]);
				i++;
			}
			levantarSemaforo(id_semaforo);
			usleep(1000000);
	
		}
		while(&lec[0]!=0x00);

		
		

		
	



	}






	return 0;



}



