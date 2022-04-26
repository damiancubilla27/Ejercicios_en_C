/*
 ============================================================================
Cubilla Damian
Ejercicio 1:
Un programa que pida al usuario un numero, despues que pida una operacion (- * + /)
y despues que pida otro numero. Segun la operacion seleccionada, se llamara a una funcion
que ejecute la operacion (restar(), multiplicar(), sumar(), dividir())
y luego mostrar al usuario el resultado.
El mostrar resultado NOOO puede estar dentro de las funciones que crean para hacer la operacion.
En la funcion dividir, no dividir por cero.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"


int main(void) {
	setbuf(stdout, NULL);

	int numUno;
	int numDos;
	int operacion;
	int enteros;
	float flotante;
	int retorno;

	printf("Ingrese un numero: ");
	scanf("%d", &numUno);
	printf("Ingresar la operacion( 1.Sumar / 2.Restar / 3.Multiplicar / 4.Dividir ): ");
	scanf("%d", &operacion);
	printf("Ingrese otro numero: ");
	scanf("%d", &numDos);

	switch(operacion)
	{
		case 1:
			SumarEnteros(numUno, numDos, &enteros);
			break;
		case 2:
			RestarEnteros(numUno, numDos, &enteros);
			break;
		case 3:
			MultiplicarEnteros(numUno, numDos, &enteros);
			break;
		case 4:
			retorno=DividirEnteros(numUno, numDos, &flotante);
			break;
	}

	if(operacion==4)
	{
		if(retorno==0)
		{
			printf("No se puede hacer esta operacion!!");
		}
		else
		{
			printf("El resultado es: %.1f", flotante);
		}
	}
	else
	{
		printf("El resultado es: %d", enteros);
	}
	return EXIT_SUCCESS;
}


