#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include "eventos.h"
#include "memcomp.h"
#include "definiciones.h"
#include "colas.h"
#include "global.h"


void procesarEvento(int id_cola_mensajes, int opc_pateador, int nro_jugador){
	
	

	switch(opc_pateador){

		case 1:
			if(nro_jugador==19){
				enviar_mensaje(id_cola_mensajes,MSG_JULIAN,MSG_ARBITRO,EVT_GOL,"JULIÁN: VAMOS, ENTRÓ");
							
				break;
			}
		
			else if (nro_jugador==10){
				enviar_mensaje(id_cola_mensajes,MSG_LAUTARO,MSG_ARBITRO,EVT_GOL,"LAUTARO: GOLAZO");
								
				break;
			}
			
			

		case 2:
				if(nro_jugador==19){
					enviar_mensaje(id_cola_mensajes,MSG_JULIAN,MSG_ARBITRO,EVT_FUERA,"JULIÁN: NOOO, SE FUE..");
					break;
				}
						
				else if (nro_jugador==10){
					enviar_mensaje(id_cola_mensajes,MSG_LAUTARO,MSG_ARBITRO,EVT_FUERA,"LAUTARO: DONDE LA MANDÉ?");
					break;			
				}
			
			

		case 3:
			if(nro_jugador==19){
				enviar_mensaje(id_cola_mensajes,MSG_JULIAN,MSG_ARBITRO,EVT_PALO,"JULIÁN: NOO, PEGÓ EN EL PALO..");
				break;
			}
		
			else if (nro_jugador==10){
				enviar_mensaje(id_cola_mensajes,MSG_LAUTARO,MSG_ARBITRO,EVT_PALO,"LAUTARO: ROMPÍ EL PALO");
				break;
			}
			
			

		case 4:
				if(nro_jugador==19){
					enviar_mensaje(id_cola_mensajes,MSG_JULIAN,MSG_ARBITRO,EVT_ATAJA,"JULIÁN: LA ATAJÓ ONANA");
					break;
				}
						
				else if (nro_jugador==10){
					enviar_mensaje(id_cola_mensajes,MSG_LAUTARO,MSG_ARBITRO,EVT_ATAJA,"LAUTARO: LA ATAJÓ EDERSON");
					break;			
				}
			
	
		default:
			break;
	}
	

}
