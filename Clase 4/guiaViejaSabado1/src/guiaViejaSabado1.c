/*
 ============================================================================
 Cubilla Damian
Ejercicio 2-1:
Crear una función que reciba como parámetro dos números enteros, que realice el
promedio de los números y que retorne dicho valor.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
float PromedioDeNumeros(int numUno, int numDos);

int main(void) {
	setbuf(stdout, NULL);
	int numeroUno;
	int numeroDos;
	float promedio;

	printf("Ingrese numero: ");
	scanf("%d", &numeroUno);
	printf("Ingrese numero: ");
	scanf("%d", &numeroDos);
	promedio=PromedioDeNumeros(numeroUno, numeroDos);
	printf("El promedio de los numeros es: %.2f", promedio);
	return EXIT_SUCCESS;
}

float PromedioDeNumeros(int numUno, int numDos)
{
	float retorno;
	int suma;
	suma=numUno+numDos;
	retorno=(float)suma/2;
	return retorno;
}
