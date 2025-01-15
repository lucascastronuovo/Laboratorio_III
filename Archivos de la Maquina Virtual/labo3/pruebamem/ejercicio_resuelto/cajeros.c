#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <time.h>
#include "utiles.h"
#define ROJO 0
#define VERDE 1
#define CANTIDAD 100
#define DESDE_IMPORTE 10
#define HASTA_IMPORTE 50
#define DESDE_CHEQUE 0
#define HASTA_CHEQUE 1
#define DESDE_INTERVALO 1000
#define HASTA_INTERVALO 2500
#define SEMAFORO0 0
#define CANT_SEMAFORO 1
#define CAJERO 1

struct tipo_inicial{

	int inicializado;

};

typedef struct tipo_dato dato;
struct tipo_dato
{
	int cajero;
	int importe;
	int cheque;
	int listo;
};
key_t creo_clave()
{
	key_t clave;
	clave = ftok("/bin/ls", 33);
	if (clave == (key_t)-1)
	{
		printf("No puedo conseguir clave para memoria compartida\n");
		exit(0);
	}
	return clave;
}
void* creo_memoria(int size, int* r_id_memoria)
{
	void* ptr_memoria;
	int id_memoria;
	id_memoria = shmget(creo_clave(), size, 0777 | IPC_CREAT);
	if (id_memoria == -1)
	{
		printf("No consigo id para memoria compartida\n");
		exit(0);
	}
	ptr_memoria = (void*)shmat(id_memoria, (char*)0, 0);
	if (ptr_memoria == NULL)
	{
		printf("No consigo memoria compartida\n");
		exit(0);
	}
	*r_id_memoria = id_memoria;
	return ptr_memoria;
}

int creo_semaforo()
{
	key_t clave = creo_clave();
	int id_semaforo = semget(clave, 1, 0600 | IPC_CREAT);


		if (id_semaforo == -1)
		{
			printf("Error: no puedo crear semaforo\n");
			exit(0);
		}
	return id_semaforo;
}

void inicia_semaforo(int id_semaforo, int valor)
{
	semctl(id_semaforo, 0, SETVAL, valor);
}

void levanta_semaforo(int id_semaforo)
{
	struct sembuf operacion;
	printf("Levanta SEMAFORO \n");
	operacion.sem_num = 0;
	operacion.sem_op = 1; 
	operacion.sem_flg = 0;
	semop(id_semaforo, &operacion, 1);
}

void espera_semaforo(int id_semaforo)
{
	struct sembuf operacion;
	printf("Espera SEMAFORO \n");
	operacion.sem_num = 0;
	operacion.sem_op = -1; 
	operacion.sem_flg = 0;
	semop(id_semaforo, &operacion, 1);
}



int main(int argc, char* argv[])
{
	inicial *memoria_ini =0;
	dato* memoria = NULL;
	int id_memoria;
	int i, aleatorio;
	int id_semaforo;
	int importe, posicion, cheque;

	int cajero = CAJERO;
	if (argc > 1)
	{

		cajero = atoi(argv[1]);
	}
	memoria_ini = (inicial*)creo_memoria(sizeof(inicial), &id_memoria);

	configurarMemoriaInicial(memoria_ini);
	
	verificarMemoriaInicial(memoria_ini);
	shmdt ((char *)memoria_ini);

	printf("Cajero %d\n", cajero);

	

	srand(time(NULL) - cajero);
	id_semaforo = creo_semaforo();

	
	
	memoria = (dato*)creo_memoria(sizeof(dato) * CANTIDAD, &id_memoria);
	while (1)
	{
		printf("Cajero\n");
		importe = rand() % (HASTA_IMPORTE - DESDE_IMPORTE + 1) + DESDE_IMPORTE;
		cheque = rand() % (HASTA_CHEQUE - DESDE_CHEQUE + 1) + DESDE_CHEQUE;
		espera_semaforo(id_semaforo);
		posicion = -1;
		i = 0;
		while (posicion == -1 && i < CANTIDAD)
		{
			if (memoria[i].listo == 0) 
			{

				posicion = i;

				memoria[posicion].cajero = cajero;
				memoria[posicion].importe = importe;
				memoria[posicion].cheque = cheque;
				memoria[posicion].listo = 1;

				printf("Posicion %d\n", posicion);
				printf("Cajero %d\n", memoria[posicion].cajero);
				printf("Importe %d\n", memoria[posicion].importe);
				printf("cheque %d\n", memoria[posicion].cheque);
				printf("listo %d\n", memoria[posicion].listo);
			}
			i++; 
		};
		levanta_semaforo(id_semaforo);
		usleep((rand() % (HASTA_INTERVALO - DESDE_INTERVALO + 1) + DESDE_INTERVALO) * 1000);
	}
	return 0;
}
