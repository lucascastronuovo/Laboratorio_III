#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include "clave.h"



key_t creo_clave(int r_clave){


	key_t clave;
	clave = ftok ("/bin/ls", r_clave);

	if(clave == (key_t)-1){

		printf("No se puede conseguir clave\n");
		exit(0);
	}

	return clave;


}
