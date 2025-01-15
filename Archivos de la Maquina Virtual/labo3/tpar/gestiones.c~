#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestiones.h"




int abrirArchivo(char *direccion, char *modo){
	
	

	if((arc=fopen(direccion, modo))==NULL){
		
		
		return 0;
		
	}
	else{
		
		return 1;

	}
	
	

}

void cerrarArchivo(char *modo) {
			
		
	fclose(arc);
	
}

void leerArchivo(char *lec) {

	
	fscanf(arc,"%s\n",lec);


}




void escribirArchivo(char *esc) {
	
	
	
	fprintf(arc,"%s\n",esc);  /*ver si sacar el \n o no*/		



}



void renombrarArchivo(char *na, char *nn){


	rename(na, nn);


}





