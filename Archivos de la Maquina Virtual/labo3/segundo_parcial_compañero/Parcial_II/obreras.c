#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include "definiciones.h"
#include "funciones.h"
#include "semaforos.h"
#include "shm.h"
#include "colas.h"

void *funcionThread(void *parametro)
{
    hormiga *h = (hormiga *)parametro;

    int id, evento, avance;
    int id_semaforo, id_cola_mensajes, id_control, id_recursos;
    char contenido[LARGO_TMENSAJE];
    int control = 0;
    estatus *estatus_control = NULL;
    recursos *estatus_recursos = NULL;
    mensaje msg;

    pthread_mutex_t mutex;

    estatus_control = (estatus *)creo_memoria(sizeof(estatus) * 2, &id_control, CLAVE_MEMORIA);
    estatus_recursos = (recursos *)creo_memoria(sizeof(recursos) * 2, &id_recursos, CLAVE_MEMORIA + 1);

    id = h->id;
    id_cola_mensajes = h->id_cola_mensajes;
    id_semaforo = h->id_semaforo;

    espera_semaforo(id_semaforo);
    estatus_control[0].init_hormigas += 1;
    control = estatus_control->init_reina;
    levanta_semaforo(id_semaforo);

    printf("Hormiga: %d\n", id);

    while (control != 1)
    {
        /*printf("Control: %d, Hormiga: %d\n", control, id);*/
        espera_semaforo(id_semaforo);
        control = estatus_control->init_reina;
        levanta_semaforo(id_semaforo);
        sleep(0.5);
    }

    while (control == 1)
    {
        pthread_mutex_lock(&mutex);
        recibir_mensaje(id_cola_mensajes, MSG_HORMIGAS + id, &msg);
        printf("Recibi mensaje\n");
        pthread_mutex_unlock(&mutex);
        sleep(0.5);

        pthread_mutex_lock(&mutex);
        memset(contenido, 0x00, sizeof(contenido));
        strcpy(contenido, msg.char_mensaje);
        evento = msg.int_evento;
        avance = obtenerAleatorio();

        printf("Evaluo evento %d, %d\n", evento, id);

        switch (evento)
        {
        case EVT_JUNTAR_COMIDA:
            printf("Pre semaforo\n");
            espera_semaforo(id_semaforo);
            /* EL ERROR DE SEG FAULT OCURRE ACÁ */
            estatus_recursos[0].comida += avance;
            /* EL ERROR DE SEG FAULT OCURRE ACÁ */
            levanta_semaforo(id_semaforo);
            printf("Post semaforo\n");
            break;
        case EVT_JUNTAR_PALITOS:
            espera_semaforo(id_semaforo);
            estatus_recursos[0].palitos += avance;
            levanta_semaforo(id_semaforo);
            break;
        case EVT_JUNTAR_HOJAS:
            espera_semaforo(id_semaforo);
            estatus_recursos[0].hojas += avance;
            levanta_semaforo(id_semaforo);
            break;
        case EVT_JUNTAR_TIERRA:
            espera_semaforo(id_semaforo);
            estatus_recursos[0].tierra += avance;
            levanta_semaforo(id_semaforo);
            break;
        case EVT_TERMINAR_TRABAJO:
            pthread_exit(NULL);
        default:
            break;
        }

        printf("Hormiga: %d, Agregue %d %s\n", id, avance, contenido);

        control = estatus_control->init_reina;
        pthread_mutex_unlock(&mutex);
        sleep(0.5);
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int id_semaforo, id_cola_mensajes, id_control;
    int n_hormigas, i;

    estatus *estatus_control = NULL;

    hormiga *hormigas;
    pthread_t *threads;
    pthread_attr_t attr;

    srand(time(0));

    if (argc == 2)
    {
        n_hormigas = atoi(argv[1]);
        if (n_hormigas == 0)
        {
            printf("No hay hormigas para trabajar...");
            return 0;
        }
    }
    else
    {
        printf("Favor ingresar solamente el numero de hormigas como parametro!\n");
        return 0;
    }

    threads = (pthread_t *)malloc(sizeof(pthread_t) * (n_hormigas + 1));
    hormigas = (hormiga *)malloc(sizeof(hormiga) * (n_hormigas + 1));
    estatus_control = (estatus *)creo_memoria(sizeof(estatus) * 2, &id_control, CLAVE_MEMORIA);

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_COLAS);
    id_semaforo = creo_semaforo(CLAVE_SEMAFORO);

    espera_semaforo(id_semaforo);
    estatus_control[0].cantidad_hormigas = n_hormigas;
    levanta_semaforo(id_semaforo);

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < n_hormigas; i++)
    {
        hormigas[i].id = i + 1;
        hormigas[i].id_cola_mensajes = id_cola_mensajes;
        pthread_create(&threads[i], &attr, funcionThread, &hormigas[i]);
    }

    for (i = 0; i < n_hormigas; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
