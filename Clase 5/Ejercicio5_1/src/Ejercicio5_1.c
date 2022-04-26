/*
 ============================================================================
Cubilla Damian
Ejercicio 1:
Pedir al usuario 5 edades y luego imprimir las edades. Definir un array de 5 posiciones y
usar la funcion getNumero() para pedir los valores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int UtnGetNumeroEntero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

int main(void) {
	setbuf(stdout, NULL);
	int edad;
	int edades[TAM];

	for(int i=0;i<TAM;i++)
	{
		if(UtnGetNumeroEntero(&edad, "Ingresa un numero: ", "Error en el ingreso..\n", 0, 100, 2)==0)
		{
			edades[i]=edad;
		}
		else
		{
			printf("Error en el sistema..\n");
		}
	}

	for(int j=0;j<TAM;j++)
	{
		printf("Valor: %d en la posicion %d\n", edades[j], j);
	}

	return EXIT_SUCCESS;
}

int UtnGetNumeroEntero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	int bufferInt;
	if(resultado!=NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos >=0)
	{
		do{
			printf("%s", mensaje);
			scanf("%d", &bufferInt);
			if(bufferInt>=minimo && bufferInt<=maximo)
			{
				*resultado=bufferInt;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);

	}

	return retorno;
}
