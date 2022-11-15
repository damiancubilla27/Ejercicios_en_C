/*
 ============================================================================
Cubilla Damian
Ejercicio 15-1:
Realizar el ordenamiento de un vector de enteros. Para ello deberán crear una
función que se encargue de realizar el intercambio de los dos valores que se
van a ordenar (función swap), que solo puede recibir dos parámetros.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void realizaIntercambio(int* puntero, int tam);

int main(void) {
	setbuf(stdout, NULL);
	int enteros[10]={3,6,10,33,77,4,2,9,5,55};
	int* pEnteros;
	pEnteros = enteros;
	realizaIntercambio(pEnteros, 10);

	for(int i=0;i<10;i++)
	{
		printf("%d\n", *(pEnteros+i));
	}

	return EXIT_SUCCESS;
}

void realizaIntercambio(int* puntero, int tam)
{
	int aux;
	for(int i=0;i<tam-1;i++)
	{
		for(int j=i+1;j<tam;j++)
		{
			if(*(puntero+i)>*(puntero+j))
			{
				aux=*(puntero+i);
				*(puntero+i)=*(puntero+j);
				*(puntero+j)=aux;
			}
		}
	}
}
