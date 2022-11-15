/*
 ============================================================================
 Cubilla Damian
2-Realizar una función que reciba como parámetros un array de enteros y un entero por referencia.
La función calculará el valor máximo de ese array y utilizará el valor por referencia para retornar ese valor.
Utilizar aritmetica de punteros

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void retornaValorMaximoArray(int array[], int* puntero, int tam);

int main(void) {
	setbuf(stdout, NULL);

	int numeros[5]={5,7,11,13,2};
	int entero;

	retornaValorMaximoArray(numeros, &entero, 5);

	printf("El numero maximo es: %d", entero);

	return EXIT_SUCCESS;
}

void retornaValorMaximoArray(int array[], int* puntero, int tam)
{
	int max;
	for(int i=0;i<tam;i++)
	{
		if(i==0 || *(array+i)>max)
		{
			max=*(array+i);
		}
	}

	*puntero=max;
}
