#ifndef _COLAS
#define _COLAS



typedef struct tipo_mensajes mensaje;
struct tipo_mensajes
{
	long	long_dest; 			
	int 	int_rte;			
	int 	int_evento;						
	char 	char_mensaje[1024];
};

extern mensaje msg;


int 	creo_id_cola_mensajes(int);

int 	borrar_mensajes(int);

int 	recibir_mensaje(int, long , mensaje*);

int 	enviar_mensaje(int, long, int, int, char*);

#endif

