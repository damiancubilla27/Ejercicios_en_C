/*
 ============================================================================
Cubilla Damian
Ejercicio 6-1:
Disponemos de dos variables numéricas (a y b).
Realizar un algoritmo que permita el intercambio de valores de dichas variables.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int a = 3;
	int b = 10;
	int aux;

	aux=a;
	a=b;
	b=aux;


	printf("A: %d  -- B: %d", a, b);

	return EXIT_SUCCESS;
}


