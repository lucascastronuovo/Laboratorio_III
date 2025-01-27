#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "def_gen.h"
#include "gestiones.h"
#include "semaforo.h"

struct paneles {

	int nro_panel;
	char mensaje[LARGO];

};


int main(int argc, char *argv[]){
	
	
	struct paneles panel;
	char msj_default[LARGO] = "default";
	char linea[LARGO];
	char linea_actual[LARGO];
	int id_semaforo;	


	id_semaforo =  crearSemaforo();

	if(argc==2){
		
		panel.nro_panel = atoi(argv[1]);


		if(panel.nro_panel > 3 || panel.nro_panel < 1){

			printf("Parámetro ingresado no válido\n");
		
		}
		else{
			snprintf(&panel.mensaje[0], sizeof(panel.mensaje),"%s\n",&msj_default[0]);
			snprintf(&linea[0], sizeof(linea),"%s\n",&msj_default[0]);
			reemplazarLineaArchivo(arc,&panel.mensaje[0],panel.nro_panel,"paneles.txt");
			
		}
		
	}
	else{
		printf("No se ingresaron paramentros\n");	
	}

	while(1){

		

		memset(&linea_actual[0],0x00,sizeof(linea_actual));
		esperarSemaforo(id_semaforo);		
		arc=abrirArchivo("paneles.txt","r");
		obtenerLineaArchivo(arc,&linea_actual[0],sizeof(linea_actual),panel.nro_panel);
		cerrarArchivo(arc);
		levantarSemaforo(id_semaforo);
			

		if(strcmp(&linea[0],&linea_actual[0])!=0){

			
			printf("%s\n", &linea_actual[0]);
			snprintf(&linea[0], sizeof(linea),"%s\n",&linea_actual[0]);
		
		}
		
		usleep(1000000);
		
	
	}
	
	


	return 0;


}
