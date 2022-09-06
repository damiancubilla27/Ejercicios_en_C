/*
 ============================================================================
Cubilla Damian
ejercicio 2:
Pedir al usuario 5 numeros e imprimir el promedio.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int acumulador;
	float promedio;
	acumulador=0;

	for(int i=0;i<5;i++)
	{
		printf("Ingrese numero: ");
		scanf("%d", &numero);
		acumulador=acumulador+numero;
	}

	promedio=(float)acumulador/5;
	printf("PROMEDIO: %.2f", promedio);
	return EXIT_SUCCESS;
}
