/*
 * mostrarYPedir.c
 *
 *  Created on: 22 sep. 2022
 *      Author: damia
 */

#include "mostrarYPedir.h"

void jugadorPorConfederacion(int numero, int asia, int africa, int zNorte, int suda, int euro, int ocea, int* asi, int* afri, int* norte, int* sudame, int* europa, int* oceania)
{
	int acumulador;
	acumulador=0;
	switch(numero)
	{
	case 1:
		acumulador++;
		acumulador+=asia;
		*asi=acumulador;
		break;
	case 2:
		acumulador++;
		acumulador+=africa;
		*afri=acumulador;
		break;
	case 3:
		acumulador++;
		acumulador+=zNorte;
		*norte=acumulador;
		break;
	case 4:
		acumulador++;
		acumulador+=suda;
		*sudame=acumulador;
		break;
	case 5:
		acumulador++;
		acumulador+=euro;
		*europa=acumulador;
		break;
	case 6:
		acumulador++;
		acumulador+=ocea;
		*oceania=acumulador;
		break;
	}
}

int validarConfederacion(void)
{
	int confedera;
	do
	{
		printf("Confederacion del jugador:\n1. AFC\n2. CAF\n3. CONCACAF\n4. CONMEBOL\n5. UEFA\n6. OFC\nIngrese Confederacion: ");
		scanf("%d", &confedera);
		if(confedera>6 || confedera<1)
		{
			printf("Reingrese ");
		}
	}while(confedera!=1 && confedera!=2 && confedera!=3 && confedera!=4 && confedera!=5 && confedera!=6);

	return confedera;
}

int validarNumeroPosicion(void)
{
	int posi;
	do
	{
		printf("Posicion del jugador:\n1. Arquero\n2. Defensor\n3. Mediocampista\n4. Delantero\nIngrese Posicion: ");
		scanf("%d", &posi);
		if(posi>4 || posi<1)
		{
			printf("Reingrese ");
		}
	}while(posi!=1 && posi!=2 && posi!=3 && posi!=4);

	return posi;
}

int jugadorPorPosicion(int posicion, int arq, int def, int med, int del, int* arquero, int* defensor, int* medio, int* delantero)
{
	int retorno;
	int acumulador;
	acumulador=0;
	switch(posicion)
	{
	case 1:
		acumulador++;
		acumulador+=arq;
		if(acumulador<3)
		{
			*arquero=acumulador;
			retorno=1;
		}
		else
		{
			printf("Ya estan los seleccionados para la posicion de Arquero!\n");
			retorno=0;
		}
		break;
	case 2:
		acumulador++;
		acumulador+=def;
		if(acumulador<9)
		{
			*defensor=acumulador;
			retorno=1;
		}
		else
		{
			printf("Ya estan los seleccionados para la posicion de Defensor!\n");
			retorno=0;
		}
		break;
	case 3:
		acumulador++;
		acumulador+=med;
		if(acumulador<9)
		{
			*medio=acumulador;
			retorno=1;
		}
		else
		{
			printf("Ya estan los seleccionados para la posicion de Mediocampistas!\n");
			retorno=0;
		}
		break;
	case 4:
		acumulador++;
		acumulador+=del;
		if(acumulador<5)
		{
			*delantero=acumulador;
			retorno=1;
		}
		else
		{
			printf("Ya estan los seleccionados para la posicion de Delanteros!\n");
			retorno=0;
		}
		break;
	}
	return retorno;
}


void ingresoDeMantenimiento(float hos, float com, float tran,float* hospe, float* comi, float* transp)
{
	char seguir;
	int numero;
	float buffer;
	if(hospe != NULL && comi != NULL && transp != NULL)
	{
		do
		{
			printf("Ingrese 1 para Hospedaje, 2 para Comida, 3 para Transporte: ");
			scanf("%d", &numero);
			switch(numero)
			{
				case 1:
					printf("Costo de Hospedaje: ");
					scanf("%f", &buffer);
					buffer+=hos;
					*hospe = buffer;
					break;
				case 2:
					printf("Costo de Comida: ");
					scanf("%f", &buffer);
					buffer+=com;
					*comi = buffer;
					break;
				case 3:
					printf("Costo de Transposte: ");
					scanf("%f", &buffer);
					buffer+=tran;
					*transp = buffer;
					break;
			}
			printf("Desea ingresar otro costo? s/n");
			fflush(stdin);
			scanf("%c", &seguir);
		}while(seguir=='s');
	}
}


void utn_getNumeroEntero(int* pNum, char* mensajeError, int min, int max, int reintentos, float hos, float com, float trans, int arq, int def, int med, int del)
{
    int bufferInt;
    if(pNum!=NULL && mensajeError != NULL && min<=max && reintentos >=0)
    {

		do
		{
			printf("\n\t\tMenu Principal\n\n1.Ingreso de los costos de Mantenimiento\n Costo de Hospedaje -> $ %.2f\n Costo de Comida -> $ %.2f\n Costo de Transporte -> $ %.2f\n2.Carga de jugadores\n Arqueros -> %d\n Defensores -> %d\n Mediocampistas -> %d\n Delanteros -> %d\n3.Realizar todos los calculos\n4.Informar todos los resultados\n5.Salir\nIngrese opcion: ", hos, com, trans, arq, def, med, del);
			scanf("%d", &bufferInt);
			if(bufferInt >= min && bufferInt <= max)
			{
				*pNum = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
				if(reintentos<0)
				{
					*pNum=5;
				}
			}

		}while(reintentos>=0);
    }
}
