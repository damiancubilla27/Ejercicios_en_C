/*
 ============================================================================
 Cubilla Damian
Ejercicio 2-1:
Crear una función que reciba como parámetro un número entero. La función retorna 1
en caso de que sea positivo, -1 en caso de que sea negativo y 0 en caso de que sea 0.
Realizar la prueba lógica de la función en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int claseDeNumero(int num);

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int num;
	printf("Ingrese numero: ");
	scanf("%d", &numero);
	num=claseDeNumero(numero);
	printf("La función retorna 1 en caso de que sea positivo, -1 en caso de que sea negativo y 0 en caso de que sea 0 : %d", num);
	return EXIT_SUCCESS;
}

int claseDeNumero(int num)
{
	int retorno;
	if(num>0)
	{
		retorno=1;
	}
	else if(num<0)
	{
		retorno=-1;
	}
	else
	{
		retorno=0;
	}
	return retorno;
}
