/*
 * utnGet.c
 *
 *  Created on: 13 abr. 2022
 *      Author: damia
 */


#include <stdio.h>
#include <stdlib.h>

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

int UtnGetNumeroFlotante(float *resultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno=-1;
	float bufferFloat;
	if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos >=0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%f", &bufferFloat);
			if(bufferFloat>=minimo && bufferFloat<=maximo)
			{
				*resultado=bufferFloat;
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

int UtnGetCaracter(char *resultado, char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char minimoMinuscula, char maximoMinuscula)
{
	int retorno=-1;
	char bufferChar;
	do
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &bufferChar);
		if((bufferChar>=minimo && bufferChar<=maximo) || (bufferChar>=minimoMinuscula && bufferChar<=maximoMinuscula))
		{
			*resultado=bufferChar;
			retorno=0;
			break;
		}
		else
		{
			printf("%s", mensajeError);
			reintentos--;
		}

	}while(reintentos>=0);
	return retorno;
}
