#ifndef _DEFINICIONES_H
#define _DEFINICIONES_H

#define CLAVE_SEMAFORO 21
#define CLAVE_MEMORIA 26
#define CLAVE_COLAS 28

#define ROJO 0
#define VERDE 1
#define DESDE 1
#define HASTA 4
#define LARGO 150 + 1
#define CORTO 10 + 1
#define LARGO_TMENSAJE 1024

#define MAX_MENU 4

typedef struct t_status estatus;
struct t_status
{
    int init_reina;
    int init_hormigas;
    int cantidad_hormigas;
};

typedef struct t_recursos recursos;
struct t_recursos
{
    int comida;
    int palitos;
    int hojas;
    int tierra;
};

typedef struct t_hormiga hormiga;
struct t_hormiga
{
    int id_cola_mensajes;
    int id_semaforo;
    int id;
};

typedef enum
{
    MSG_NADIE,
    MSG_REINA,
    MSG_HORMIGAS
} Destinos;

typedef enum
{
    EVT_SALIR,
    EVT_JUNTAR_COMIDA,
    EVT_JUNTAR_PALITOS,
    EVT_JUNTAR_HOJAS,
    EVT_JUNTAR_TIERRA,
    EVT_TERMINAR_TRABAJO
} Eventos;

#endif
