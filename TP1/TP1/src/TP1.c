/*
 ============================================================================
Cubilla Damian
Division: 1F
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mostrarYPedir.h"
#include "calculosMatematicos.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	float hospedaje;
	float comida;
	float transporte;
	int posicion;
	int jugador;
	int retorno;
	int camiseta;
	int arqueros;
	int defensores;
	int mediocampistas;
	int delanteros;
	int opcionConfedera;
	int afc;
	int caf;
	int concacaf;
	int conmebol;
	int uefa;
	int ofc;
	float afcP;
	float cafP;
	float concaP;
	float conmeP;
	float uefaP;
	float ofcP;
	float totalMantenimiento;
	float aumento;
	float nuevoValor;
	int bandera;

	hospedaje=0;
	comida=0;
	transporte=0;
	jugador=0;
	arqueros=0;
	defensores=0;
	mediocampistas=0;
	delanteros=0;
	afc=0;
	caf=0;
	concacaf=0;
	conmebol=0;
	uefa=0;
	ofc=0;
	afcP=0;
	cafP=0;
	concaP=0;
	conmeP=0;
	uefaP=0;
	ofcP=0;
	totalMantenimiento=0;
	bandera=0;

	do
	{
		utn_getNumeroEntero(&opcion,"Error en el ingreso de datos...\n", 1, 5, 3, hospedaje, comida, transporte, arqueros, defensores, mediocampistas, delanteros);
		switch(opcion)
		{
			case 1:
				ingresoDeMantenimiento(hospedaje, comida, transporte, &hospedaje, &comida, &transporte);
				break;
			case 2:
				if(jugador<22)
				{
					posicion=validarNumeroPosicion();
					retorno=jugadorPorPosicion(posicion,arqueros, defensores, mediocampistas, delanteros, &arqueros, &defensores, &mediocampistas, &delanteros);
					if(retorno==1)
					{
						printf("Ingrese camiseta: ");
						scanf("%d", &camiseta);
						opcionConfedera=validarConfederacion();
						jugadorPorConfederacion(opcionConfedera, afc, caf, concacaf, conmebol, uefa, ofc, &afc, &caf, &concacaf, &conmebol, &uefa, &ofc);
						jugador++;
					}
				}
				else
				{
					printf("Ya tenemos los convocados al mundial!!");
				}
				break;
			case 3:
				if((hospedaje!=0 || comida!=0 || transporte!=0) && jugador!=0)
				{
					afcP=calcularPromedio(afc, jugador);
					cafP=calcularPromedio(caf, jugador);
					concaP=calcularPromedio(concacaf, jugador);
					conmeP=calcularPromedio(conmebol, jugador);
					uefaP=calcularPromedio(uefa, jugador);
					ofcP=calcularPromedio(ofc, jugador);
					totalMantenimiento=calcularMantenimiento(hospedaje, comida, transporte);
					printf("\nLos calculos se realizaron correctamente.\n");
					bandera=1;
				}
				break;
			case 4:
				if(bandera==1)
				{
					printf("Promedio UEFA: %.2f\n", uefaP);
					printf("Promedio CONMEBOL: %.2f\n", conmeP);
					printf("Promedio CONCACAF: %.2f\n", concaP);
					printf("Promedio AFC: %.2f\n", afcP);
					printf("Promedio OFC: %.2f\n", ofcP);
					printf("Promedio CAF: %.2f\n", cafP);
					if(calcularJugadoresEnEuropa(jugador)<uefa)
					{
						aumento=calcularAumento(totalMantenimiento);
						nuevoValor=costoTotal(totalMantenimiento, aumento);
						printf("El costo por mantenimiento era de %.2f y recibio un aumento de $%.2f , su nuevo valor es de: $%.2f\n", totalMantenimiento, aumento, nuevoValor);
					}
					else
					{
						printf("El costo por mantenimiento es %.2f\n", totalMantenimiento);
					}
				}
				break;
		}
	}while(opcion!=5);
	return EXIT_SUCCESS;
}

