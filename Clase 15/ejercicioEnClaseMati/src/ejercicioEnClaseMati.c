/*
 ============================================================================
 Cubilla Damian
 Realizar un algoritmo que me permita los valores de dos variables
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int intercambiarNumeros(int* numUno, int* numDos);

int main(void) {
	setbuf(stdout, NULL);
	int uno=3;
	int dos=10;

	if(intercambiarNumeros(&uno, &dos)==0)
	{
		printf("%d --- %d", uno, dos);
	}
	else
	{
		printf("No se pudo realixar el intercambio");
	}

	return EXIT_SUCCESS;
}

int intercambiarNumeros(int* numUno, int* numDos)
{
	int retorno=-1;
	int aux;
	if(numUno!=NULL && numDos!=NULL)
	{
		aux=*numUno;
		*numUno=*numDos;
		*numDos=aux;
		retorno=0;
	}
	return retorno;
}
