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

void cerrarArchivo() {
			
		
	fclose(arc);
	
}

void leerArchivo(char *lec) {

	
	fscanf(arc,"%s",lec);



}

void leerArchivoConEspacios(char *lec, int tam){


	fgets(lec,tam,arc);


}


void escribirArchivo(char *esc) {
	
	
	
	fprintf(arc,"%s",esc);	



}



void renombrarArchivo(char *na, char *nn){


	rename(na, nn);


}





