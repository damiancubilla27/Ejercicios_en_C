/*
 ============================================================================
Cubilla Damian
Ejercicio 3-2:
Crear una funci�n que permita determinar si un n�mero es par o no.
La funci�n retorna 1 en caso afirmativo y 0
en caso contrario. Probar en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int DeterminarParOImpar(int num);

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int resultado;
	printf("Ingrese numero: ");
	scanf("%d", &numero);
	resultado = DeterminarParOImpar(numero);
	if(resultado == 1)
	{
		printf("Su numero es par!");
	}
	else
	{
		printf("Su numero es impar!!");
	}
	return EXIT_SUCCESS;
}

int DeterminarParOImpar(int num)
{
	int retornar;
	if(num%2==0)
	{
		retornar=1;
	}
	else
	{
		retornar=0;
	}
	return retornar;
}
