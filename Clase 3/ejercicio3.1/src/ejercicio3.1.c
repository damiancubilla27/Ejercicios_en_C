/*
 ============================================================================
Cubilla Damian
Ejercicio 3-1:
Crear una función que muestre por pantalla el número flotante  que recibe como parámetro.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void MostrarFlotante(float num);

int main(void) {
	setbuf(stdout, NULL);
	float numero;
	printf("Ingrese un numero flotante: ");
	scanf("%f", &numero);
	MostrarFlotante(numero);
	return EXIT_SUCCESS;
}

void MostrarFlotante(float num)
{
	printf("El numero es %.2f", num);
}
