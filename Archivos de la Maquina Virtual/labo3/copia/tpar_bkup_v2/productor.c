#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestiones.h"
#include "productor.h"





void producir(){

	int n;
	char direccion[20];
	char modo[20];
	char esc[20];
	int a;


	memset(&direccion[0],0x00,sizeof(direccion));
	memset(&modo[0],0x00,sizeof(modo));

	strcpy(&direccion[0], "producto.txt");
	strcpy(&modo[0], "w");
	a=abrirArchivo(&direccion[0], &modo[0]);

	if(a==0){
		
		printf("No se puede Abrir\n");
	}
	else{
		if(a==1){
			for(n=1;n<11;n++){
		
				memset(&esc[0],0x00,sizeof(esc));
				printf("PRODUCTO-%02d\n",n);
				scanf("%s", &esc[0]);
				escribirArchivo(&esc[0], n);	
			
			}
		
			fclose(arc);
			/*cerrarArchivo(&modo[0]);*/
		
		}
		
	}
	


}
