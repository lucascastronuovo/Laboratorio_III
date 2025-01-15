#ifndef _SEMAFORO_H
#define _SEMAFORO_H

int crearSemaforo();

void iniciarSemaforo(int id_semaforo, int valor);

void levantarSemaforo(int id_semaforo);

void esperarSemaforo(int id_semaforo);



#endif
