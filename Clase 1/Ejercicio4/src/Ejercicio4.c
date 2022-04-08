/*
 ============================================================================
 Cubilla Damian
 Ejercicio 4:
 Pedir dos numeros e imprimir la suma, la resta, la division y la multiplicacion.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int numeroUno;
	int numeroDos;
	int suma;
	int resta;
	float divi;
	int multi;

	printf("Ingrese un numero: ");
	scanf("%d", &numeroUno);
	printf("Ingrese otro numero: ");
	scanf("%d", &numeroDos);

	suma=numeroUno+numeroDos;
	resta=numeroUno-numeroDos;
	divi= (float)numeroUno/numeroDos;
	multi=numeroUno*numeroDos;

	printf("La suma de los numeros es: %d\n", suma);
	printf("La resta de los numeros es: %d\n", resta);
	printf("La division de los numeros es: %.2f\n", divi);
	printf("La multiplicacion de los numeros es: %d\n", multi);

	return EXIT_SUCCESS;
}
