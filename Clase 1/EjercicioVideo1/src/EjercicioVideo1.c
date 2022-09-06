/*
 ============================================================================
Cubilla Damian
Ejercicio 1:
Pedir dos numeros e imprimir la suma, la resta, la division y la multiplicacion
de los numeros.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numeroUno;
	int numeroDos;
	int suma;
	int resta;
	float division;
	int multi;

	printf("Ingrese un numero: ");
	scanf("%d", &numeroUno);
	printf("Ingrese otro numero: ");
	scanf("%d", &numeroDos);
	suma=numeroUno+numeroDos;
	resta=numeroUno-numeroDos;
	division=(float)numeroUno/numeroDos;
	multi=numeroUno*numeroDos;
	printf("SUMA: %d - RESTA: %d - DIVISION: %.2f - MULTIPLICACION: %d", suma, resta, division, multi);

	return EXIT_SUCCESS;
}
