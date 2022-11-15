/*
 * videoGerman.c
 *
 *  Created on: 16 sep. 2022
 *      Author: damia
 */
#include <stdio.h>
#include <stdlib.h>
#include "videoGerman.h"

void ingresarNumeros(int num[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("Ingrese numero: ");
		scanf("%d", &num[i]);
	}
}

void validarNumeros(int num[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		while(num[i]<0 || num[i]>20)
		{
			printf("Reingrese numero: ");
			scanf("%d", &num[i]);
		}
	}
}

int buscarNumeroMaximo(int num[], int tam)
{
	int retorno;
	for(int i=0;i<tam;i++)
	{
		if(i==0 || num[i]>retorno)
		{
			retorno=num[i];
		}
	}
	return retorno;
}

int coincidirNumero(int num[], int tam, int numeroValor)
{
	int retorno;
	retorno=0;
	for(int i=0;i<tam;i++)
	{
		if(num[i]==numeroValor)
		{
			retorno++;
		}
	}
	return retorno;
}

int buscarNumeroMinimo(int num[], int tam)
{
	int retorno;
	for(int i=0;i<tam;i++)
	{
		if(i==0 || num[i]<retorno)
		{
			retorno=num[i];
		}
	}
	return retorno;
}

void imprimirIndices(int num[], int tam, int numeroValor)
{
	for(int i=0;i<tam;i++)
	{
		if(num[i]==numeroValor)
		{
			printf("%d ",i);
		}
	}
}

void esMayorADiez(int num[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		if(num[i]>10)
		{
			printf("\nc.El numero %d es mayor a 10 - indice %d", num[i], i);
		}
	}
}

void mostrarArray(int num[], int tam)
{
	printf("\nd. Lista de numeros ingresados: ");
	for(int i=0;i<tam;i++)
	{
		printf("%d ", num[i]);
	}
}

void mostrarMenorMayorQue(int num[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		if(num[i]>17 || num[i]<3)
		{
			printf("\ne. El numero %d ,es mayor a 17 o menor a 3!", num[i]);
		}
	}
}

float promedioNumeros(int num[], int tam)
{
	float retorno;
	int acumulador;
	acumulador=0;
	for(int i=0;i<tam;i++)
	{
		acumulador+=num[i];
	}
	retorno=(float)acumulador/tam;
	return retorno;
}
