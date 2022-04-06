/*
 ============================================================================
Cubilla Damian
Ejercicio 2:
Pedir 5 y luego imprimir el promedio.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int numeroUno;
	int numeroDos;
	int numeroTres;
	int numeroCuatro;
	int numeroCinco;
	int suma;
	float promedio;

	printf("Ingrese un numero: ");
	scanf("%d", &numeroUno);
	printf("Ingrese un numero: ");
	scanf("%d", &numeroDos);
	printf("Ingrese un numero: ");
	scanf("%d", &numeroTres);
	printf("Ingrese un numero: ");
	scanf("%d", &numeroCuatro);
	printf("Ingrese un numero: ");
	scanf("%d", &numeroCinco);

	suma = numeroUno+numeroDos+numeroTres+numeroCuatro+numeroCinco;
	promedio = (float)suma/5;

	printf("El promedio de los 5 numeros es: %.2f", promedio);

	return EXIT_SUCCESS;
}
