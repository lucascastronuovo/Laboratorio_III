#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestiones.h"
#include "productor.h"
#include "consumidor.h"

int main(int argc, char *argv[]){
	
	
	/*producir();
	-----

	consumir();*/

	abrirMenu();
	
	/*
	FILE *pro;
	FILE *con;


	int n,s;
	if((pro=fopen("producto.txt","w"))==NULL){
		
		printf("No se puede Abrir\n");
	}
	else{
		for(n=1;n<11;n++){
		
			producir(pro, n);
			
		}

		
	}
	
	fclose(pro);

	for(s=1;s<=3;s++){
	
		printf("-------------\n");	
	}
	
	if((con=fopen("producto.txt","r"))==NULL){
		
		printf("No se puede Abrir\n");
	}
	else{
		
		consumir(con);

	}
	
	fclose(con);
	*/
	
	return 0;


}