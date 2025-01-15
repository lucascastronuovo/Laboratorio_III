#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include "clave.h"
#include "colas.h"

int creo_id_cola_mensajes(int clave)
{
    int id_cola_mensajes = msgget(creo_clave(clave), 0600 | IPC_CREAT);
    if (id_cola_mensajes == -1)
    {
        printf("Error al obtener identificador para cola mensajes\n");
        exit(-1);
    }
    return id_cola_mensajes;
}

int enviar_mensaje(int id_cola_mensajes, long rLongDest, int rIntRte, int rIntEvento, char *repCharMsg)
{
    mensaje msg;
    int t_size = 0;
    msg.long_dest = rLongDest;
    msg.int_rte = rIntRte;
    msg.int_evento = rIntEvento;
    strcpy(msg.char_mensaje, repCharMsg);
    t_size = sizeof(msg.int_rte) + sizeof(msg.int_evento) + sizeof(msg.char_mensaje);

    return msgsnd(id_cola_mensajes, (struct msgbuf *)&msg, t_size, IPC_NOWAIT);
}

int recibir_mensaje(int id_cola_mensaje, long rLongDest, mensaje *rMsg)
{
    mensaje msg;
    int t_size = 0;
    int res;
    t_size = sizeof(msg.int_rte) + sizeof(msg.int_evento) + sizeof(msg.char_mensaje);
    res = msgrcv(id_cola_mensaje, (struct msgbuf *)&msg, t_size, rLongDest, 0);

    rMsg->long_dest = msg.long_dest;
    rMsg->int_rte = msg.int_rte;
    rMsg->int_evento = msg.int_evento;
    strcpy(rMsg->char_mensaje, msg.char_mensaje);

    return res;
}

int borrar_mensajes(int id_cola_mensajes)
{
    mensaje msg;
    int t_size = sizeof(msg.int_rte) + sizeof(msg.int_evento) + sizeof(msg.char_mensaje);
    int res;
    do
    {
        res = msgrcv(id_cola_mensajes, (struct msgbuf *)&msg, t_size, 0, IPC_NOWAIT);
    } while (res > 0);

    return res;
}

int destruir_cola(int id_cola_mensajes)
{
    return msgctl(id_cola_mensajes, IPC_RMID, NULL);
}
