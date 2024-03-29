#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "jugador.h"

int utn_getEnteroCorto(short* entero, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno=-1;
	short numeroIngresado;
	if(entero!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo)
	{
		printf("%s", mensaje);
		scanf("%hd", &numeroIngresado);
		while(numeroIngresado<minimo || numeroIngresado>maximo)
		{
			printf("%s", mensajeError);
			scanf("%hd", &numeroIngresado);
		}
		*entero=numeroIngresado;
		retorno=0;
	}
	return retorno;
}

int utn_getNumeroEntero(int* entero, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno=-1;
	int numeroIngresado;
	if(entero!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo)
	{
		printf("%s", mensaje);
		scanf("%d", &numeroIngresado);
		while(numeroIngresado<minimo || numeroIngresado>maximo)
		{
			printf("%s", mensajeError);
			scanf("%d", &numeroIngresado);
		}
		*entero=numeroIngresado;
		retorno=0;
	}
	return retorno;
}

int utn_getArrayCadena(char* cadena, char* mensaje, char* mensajeError, int max)
{
	int retorno=-1;
	char buffer[256];
	int tam;
	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max>0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		tam = strlen(buffer);
		while(tam>max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			tam = strlen(buffer);
		}
		strcpy(cadena, buffer);
		retorno=0;
	}
	return retorno;
}

int utn_getNumeroFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max)
{
	int retorno=-1;
	float numeroIngresado;
	if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min<max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);
		while(numeroIngresado<min || numeroIngresado>max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}
		*flotante=numeroIngresado;
		retorno=0;
	}
	return retorno;
}

int utn_getCaracter(char* caracter, char* mensaje, char min, char max, char minMay, char maxMay)
{
	int retorno=-1;
	char caracterIngresado;
	if(caracter != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf(" %c",&caracterIngresado);
		if((caracterIngresado>=min && caracterIngresado<=max) || (caracterIngresado>=minMay && caracterIngresado<=maxMay))
		{
			*caracter=caracterIngresado;
			retorno=0;
		}
	}
	return retorno;
}

