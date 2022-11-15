/*
 ============================================================================
 Cubilla Damian - TP2 - 1F
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "jugador.h"


int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int bandera=0;

	eJugador listaJugador[TAM];
	eConfederacion listaConfederacion[6]={{1, "CONMEBOL", "SUDAMERICA", 1996},{2, "UEFA", "EUROPA", 1954},{3, "AFC", "ASIA", 1954},{4, "CAF", "AFRICA", 1957},{5, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961},{6, "OFC", "OCEANIA", 1966}};
	jugador_inicializarJugadores(listaJugador, TAM);

	do
	{
		utn_getNumeroEntero(&opcion,"-------------------------------------\n1. ALTA DE JUGADOR\n2. BAJA DE JUGADOR\n3. MODIFICACION DE JUGADOR\n4. INFORMES\n5. SALIR\n-------------------------------------\nINGRESE OPCION: " ,"-------------------------------------\n1. ALTA DE JUGADOR\n2. BAJA DE JUGADOR\n3. MODIFICACION DE JUGADOR\n4. INFORMES\n5. SALIR\n-------------------------------------\nERROR, REINGRESE OPCION: ", 1, 5);
		switch(opcion)
		{
		case 1:
			if(bandera==0 || bandera==1)
			{
				jugador_agregarJugador(listaJugador, TAM);
				bandera=1;
				system("pause");
			}
			break;
		case 2:
			if(bandera==1)
			{
				jugador_bajaDeJugador(listaJugador, TAM, listaConfederacion, 6);
				system("pause");
			}
			break;
		case 3:
			if(bandera==1)
			{
				jugador_modificarJugador(listaJugador, TAM, listaConfederacion, 6);
				system("pause");
			}
			break;
		case 4:
			if(bandera==1)
			{
				jugador_listarImformes(listaJugador, TAM, listaConfederacion, 6);
				system("pause");
			}
			break;
		case 5:
			jugador_verificarSalida(&opcion);
			break;
		}

	}while(opcion!=5);

	return EXIT_SUCCESS;
}
