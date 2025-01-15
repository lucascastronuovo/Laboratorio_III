#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include <pthread.h>
#include <unistd.h>
#include "funciones.h"
#include "definiciones.h"
#include "semaforos.h"
#include "shm.h"
#include "colas.h"

int menu(void)
{
    int opcion;

    printf("Menu\n\n");
    printf("1.\tJUNTAR COMIDA\n");
    printf("2.\tJUNTAR PALITOS\n");
    printf("3.\tJUNTAR HOJAS\n");
    printf("4.\tJUNTAR TIERRA\n\n");
    printf("0.\tSalir\n\n");
    printf("Elija opcion: ");
    while ((scanf(" %d", &opcion) != 1) || (opcion < 0) || (opcion > MAX_MENU))
    {
        printf("No valido\n\n");
        printf("Elija opcion: ");
    }
    return opcion;
}

int main(int argc, char *argv[])
{
    int id_semaforo, id_cola_mensajes, id_control, id_recursos;
    int control, n_hormigas, opcion, hormiga, i;

    int comida = 0;
    int palitos = 0;
    int hojas = 0;
    int tierra = 0;

    estatus *estatus_control = NULL;
    recursos *estatus_recursos = NULL;

    id_semaforo = creo_semaforo(CLAVE_SEMAFORO);
    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_COLAS);
    estatus_control = (estatus *)creo_memoria(sizeof(estatus) * 2, &id_control, CLAVE_MEMORIA);
    estatus_recursos = (recursos *)creo_memoria(sizeof(recursos) * 2, &id_recursos, CLAVE_MEMORIA + 1);

    srand(time(0));

    borrar_mensajes(id_cola_mensajes);
    inicia_semaforo(id_semaforo, VERDE);

    espera_semaforo(id_semaforo);
    estatus_control[0].init_reina = 0;
    estatus_control[0].init_hormigas = 0;
    estatus_control[0].cantidad_hormigas = 0;
    estatus_recursos[0].comida = 0;
    estatus_recursos[0].palitos = 0;
    estatus_recursos[0].hojas = 0;
    estatus_recursos[0].tierra = 0;
    levanta_semaforo(id_semaforo);

    control = estatus_control->cantidad_hormigas;
    n_hormigas = estatus_control->init_hormigas;

    printf("Esperando a las hormigas...\n");
    while (control == 0)
    {
        espera_semaforo(id_semaforo);
        control = estatus_control->cantidad_hormigas;
        levanta_semaforo(id_semaforo);
        sleep(0.5);
    }

    printf("Control: %d\tHormigas: %d\n", control, n_hormigas);

    while (n_hormigas != control)
    {
        printf("Hormigas: %d\n", n_hormigas);
        espera_semaforo(id_semaforo);
        n_hormigas = estatus_control->init_hormigas;
        levanta_semaforo(id_semaforo);
        sleep(1);
    }

    printf("Arrancan a trabajar las hormigas...\n");

    espera_semaforo(id_semaforo);
    estatus_control[0].init_reina = 1;
    levanta_semaforo(id_semaforo);
    sleep(0.5);

    opcion = menu();

    while (opcion != EVT_SALIR)
    {
        comida = estatus_recursos->comida;
        palitos = estatus_recursos->palitos;
        hojas = estatus_recursos->hojas;
        tierra = estatus_recursos->tierra;

        fflush(stdin);
        printf("Recursos\n");
        printf("Comida: %d\nPalitos: %d\nHojas: %d\nTierra: %d\n", comida, palitos, hojas, tierra);

        if (comida >= 90 || palitos >= 90 || hojas >= 90 || tierra >= 90)
        {
            printf("Las hormigas terminaron de trabajar...\n");
            for (i = 1; i <= n_hormigas; i++)
            {
                enviar_mensaje(id_cola_mensajes, MSG_HORMIGAS + i, MSG_REINA, EVT_TERMINAR_TRABAJO, "LISTO!");
                opcion = EVT_SALIR;
                continue;
            }
        }
        hormiga = obtenerAleatorioParam(1, n_hormigas);
        printf("Trabaja la hormiga %d, opcion %d\n", hormiga, opcion);

        switch (opcion)
        {
        case EVT_JUNTAR_COMIDA:
            enviar_mensaje(id_cola_mensajes, MSG_HORMIGAS + hormiga, MSG_REINA, EVT_JUNTAR_COMIDA, "COMIDA");
            break;
        case EVT_JUNTAR_PALITOS:
            enviar_mensaje(id_cola_mensajes, MSG_HORMIGAS + hormiga, MSG_REINA, EVT_JUNTAR_PALITOS, "PALITOS");
            break;
        case EVT_JUNTAR_HOJAS:
            enviar_mensaje(id_cola_mensajes, MSG_HORMIGAS + hormiga, MSG_REINA, EVT_JUNTAR_HOJAS, "HOJAS");
            break;
        case EVT_JUNTAR_TIERRA:
            enviar_mensaje(id_cola_mensajes, MSG_HORMIGAS + hormiga, MSG_REINA, EVT_JUNTAR_TIERRA, "TIERRA");
            break;
        case EVT_SALIR:
            printf("Dejamos de laburar...\n");
            espera_semaforo(id_semaforo);
            estatus_control[0].init_reina = 0;
            levanta_semaforo(id_semaforo);
            break;
        default:
            printf("Opcion no valida\n");
        }

        if (opcion != EVT_SALIR)
        {
            opcion = menu();
        }
    }

    shmdt((char *)estatus_control);
    shmctl(id_control, IPC_RMID, (struct shmid_ds *)NULL);
    shmdt((char *)estatus_recursos);
    shmctl(id_recursos, IPC_RMID, (struct shmid_ds *)NULL);
    destruir_cola(id_cola_mensajes);
    return 0;
}
