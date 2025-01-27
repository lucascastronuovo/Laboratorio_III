#include "funciones.h"
#include "def.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){

	int desde;
	int hasta;	
	int n, i, m, num;
	int vec[50];
	int stop; /* 0 es false y 1 es true*/

	/*validación de si se reciben los 2 argumentos*/

	if(argc==3){
		
		desde = atoi(argv[1]);
		hasta = atoi(argv[2]);
		
		m = hasta - desde;
	}
	else{
		/*valores por defecto*/
		desde = DESDE;
		hasta = HASTA;
		m=CANTIDAD;
	}

	srand(time(NULL));

	for(n=0;n<m;n++) {
		
		do{
			stop=0;
			num = obtenerNumeroAleatorio(desde,hasta);
			for (i=0;(i<m && stop==0 && n!=0);i++){
				if (vec[i]==num)
					stop=1;	
			}
		}while(stop==1);
		

	
		vec[n]=num;
		
		printf("Numero aleatorio: %d \n", vec[n]);	
	}
	return 0;
}
