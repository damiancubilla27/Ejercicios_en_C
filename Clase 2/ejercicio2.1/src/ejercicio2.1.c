/*
 ============================================================================
Cubilla Damian
Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números.
Probar la aplicación con distintos valores.
Ejemplo 1:  3 - 5 - 7 - 9 - 1
Ejemplo 2:  2 - 1 - 8 -1 - 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int acumulador=0;
	float promedio;

	for(int i=0;i<TAM;i++)
	{
		printf("Ingrese numero: ");
		scanf("%d", &numero);
		acumulador+=numero;
	}
	promedio=(float)acumulador/TAM;
	printf("El promedio es: %.2f", promedio);
	return EXIT_SUCCESS;
}
