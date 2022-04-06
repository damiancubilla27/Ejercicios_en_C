/*
 ============================================================================
 Cubilla Damian
 Ejercicio 1:
 Pedir dos numeros al usuario, sumarlos y mostrar la suma.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int numeroUno;
	int numeroDos;
	int suma;

	printf("Ingrese un numero: ");
	scanf("%d", &numeroUno);
	printf("Ingrese otro numero: ");
	scanf("%d", &numeroDos);

	suma = numeroUno+numeroDos;
	printf("La suma de los dos numeros es: %d", suma);

	return EXIT_SUCCESS;
}
