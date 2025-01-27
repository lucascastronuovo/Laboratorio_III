#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>



#include <sys/sem.h>
#define ROJO 0
#define VERDE 1
#define CANTIDAD 100
#define DESDE_IMPORTE 10
#define HASTA_IMPORTE 50
#define DESDE_CHEQUE 0
#define HASTA_CHEQUE 1
#define INTERVALO 5000
#define SEMAFORO0 0
#define CANT_SEMAFORO 1
#define CANT_MAX_CAJEROS 3

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
//funcion que crea el semaforo
int creo_semaforo()
{
	key_t clave = creo_clave();
	int id_semaforo = semget(clave, 1, 0600 | IPC_CREAT);
	//PRIMER PARAMETRO ES LA CLAVE, EL SEGUNDO CANT SEMAFORO, EL TERCERO 060
	0 LO UTILIZA CUALQUIERA, IPC ES CONSTANTE(VEA SEMAFORO)
		if (id_semaforo == -1)
		{
			printf("Error: no puedo crear semaforo\n");
			exit(0);
		}
	return id_semaforo;
}
//inicia el semaforo
void inicia_semaforo(int id_semaforo, int valor)
{
	semctl(id_semaforo, 0, SETVAL, valor);
}
//levanta el semaforo
void levanta_semaforo(int id_semaforo)struct sembuf operacion;
printf("Levanta SEMAFORO \n");
operacion.sem_num = 0;
operacion.sem_op = 1; //incrementa el semaforo en 1
operacion.sem_flg = 0;
semop(id_semaforo, &operacion, 1);
}
//espera semaforo
void espera_semaforo(int id_semaforo)
{
	struct sembuf operacion;
	printf("Espera SEMAFORO \n");
	operacion.sem_num = 0;
	operacion.sem_op = -1; //decrementa el semaforo en 1
	operacion.sem_flg = 0;
	semop(id_semaforo, &operacion, 1);
}
int main(int argc, char* argv[])
{
	dato* memoria = NULL;
	int id_memoria;
	int i, j, aleatorio;
	int id_semaforo;
	int posicion;
	int intervalo = INTERVALO;

	int total_cantidad_depositos = 0;
	int total_cantidad_efectivos = 0;
	int total_cantidad_cheques = 0;
	int total_pesos_depositos = 0;
	int total_pesos_efectivos = 0;
	int total_pesos_cheques = 0;
	int vtotal_cantidad_depositos[CANT_MAX_CAJEROS] = { 0 };
	int vtotal_cantidad_efectivos[CANT_MAX_CAJEROS] = { 0 };
	int vtotal_cantidad_cheques[CANT_MAX_CAJEROS] = { 0 };
	int vtotal_pesos_depositos[CANT_MAX_CAJEROS] = { 0 };
	int vtotal_pesos_efectivos[CANT_MAX_CAJEROS] = { 0 };
	int vtotal_pesos_cheques[CANT_MAX_CAJEROS] = { 0 };
	if (argc > 1)
	{
		intervalo = atoi(argv[1]);
	}
	//cambia la semilla para random, usa el time como semilla inicial
	srand(time(NULL));
	id_semaforo = creo_semaforo();
	inicia_semaforo(id_semaforo, VERDE);
	memoria = (dato*)creo_memoria(sizeof(dato) * CANTIDAD, &id_memoria);
	//Inicia memoria.
	for (i = 0; i < CANTIDAD; i++)
		memoria[i].listo = 0;
	while (1)
	{
		//printf("Tesorero\n");
		espera_semaforo(id_semaforo);
		i = 0;
		while (i < CANTIDAD)
		{
			if (memoria[i].listo == 1)
			{
				if (memoria[i].cajero <= CANT_MAX_CAJEROS)
				{
					memoria[i].listo = 0;
					total_cantidad_depositos++;
					total_pesos_depositos += memoria[i].importe;
					vtotal_cantidad_depositos[memoria[i].cajero - 1]++;
					vtotal_pesos_depositos[memoria[i].cajero - 1] += memoria
						[i].importe;
					if (memoria[i].cheque == 0)
					{
						total_cantidad_efectivos++;
						total_pesos_efectivos += memoria[i].importe;
						vtotal_cantidad_efectivos[memoria[i].cajero - 1]++;
						vtotal_pesos_efectivos[memoria[i].cajero - 1] += mem
							oria[i].importe;
					}
					else
					{
						total_cantidad_cheques++;
						total_pesos_cheques += memoria[i].importe;
						vtotal_cantidad_cheques[memoria[i].cajero - 1]++;
						vtotal_pesos_cheques[memoria[i].cajero - 1] += memor
							ia[i].importe;
					}
					system("clear");
					printf("TCD %d \nT$D $%d \nTCE %d \nT$E $%d \nTCC %d \nT
						$C $ % d \n\n", total_cantidad_depositos,
						total_pesos_depositos,
						total_cantidad_efectivos,
						total_pesos_efectivos,
						total_cantidad_cheques,
						total_pesos_cheques);
					for (j = 0; j < CANT_MAX_CAJEROS; j++)
					{
						printf("Cajero %d\n", j + 1);
						printf("TCD %d \nT$D $%d \nTCE %d \nT$E $%d \nTCC %d
							\nT$C $ % d \n\n", vtotal_cantidad_depositos[j],
							vtotal_pesos_depositos[j],
							vtotal_cantidad_efectivos[j],
							vtotal_pesos_efectivos[j],
							vtotal_cantidad_cheques[j],
							vtotal_pesos_cheques[j]);
					}
				}
			}
			i++;
		};
		levanta_semaforo(id_semaforo);
		usleep(intervalo * 1000);
	}
	shmdt((char*)memoria);
	shmctl(id_memoria, IPC_RMID, (struct shmid_ds*)NULL);
	return 0;
}