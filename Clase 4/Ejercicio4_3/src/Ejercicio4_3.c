/*
 ============================================================================
Cubilla Damian
Ejercicio 3:
Crear una función que reciba como parámetro un número entero. La función retorna 1 en caso de que sea positivo,
-1 en caso de que sea negativo y 0 en caso de que sea 0.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int EvaluarRetorno(int num);

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int ret;
	printf("Ingresa numero: ");
	scanf("%d", &numero);

	ret=EvaluarRetorno(numero);
	if(ret==1)
	{
		printf("El numero %d es positivo!", numero);
	}
	else if(ret==-1)
	{
		printf("El numero %d es negativo!", numero);
	}
	else
	{
		printf("El numero %d es un cero!", numero);
	}
	return EXIT_SUCCESS;
}

int EvaluarRetorno(int num)
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
