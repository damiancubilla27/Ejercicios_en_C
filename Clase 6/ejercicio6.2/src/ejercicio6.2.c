/*
 ============================================================================
Cubilla Damian
Ejercicio 6-2:
Realizar un programa que permita el ingreso de 10 números enteros (positivos y negativos).
Necesito generar un listado de los números positivos de manera creciente y negativos de manera
decreciente. (Como máximo 5 estructuras repetitivas).
Ejemplo:
Listado 1 : 4, 5, 6, 10, 18, 29
Listado 2 : -1,-5,-9,-12

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void pedirNumeros(int num[], int tam);
void ordenarArrayPositivos(int numArray[], int tam);
void ordenarArrayNegativos(int numArray[], int tam);
void imprimirNumerosPositivos(int num[], int tam);
void imprimirNumerosNegativos(int num[], int tam);

int main(void) {
	setbuf(stdout, NULL);
	int numeros[TAM];

	pedirNumeros(numeros, TAM);
	ordenarArrayPositivos(numeros, TAM);
	printf("\nListado 1: ");
	imprimirNumerosPositivos(numeros, TAM);

	ordenarArrayNegativos(numeros, TAM);
	printf("\nListado 2: ");
	imprimirNumerosNegativos(numeros, TAM);

	return EXIT_SUCCESS;
}

void pedirNumeros(int num[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("Ingrese numero: ");
		scanf("%d", &num[i]);
	}
}

void imprimirNumerosPositivos(int num[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		if(num[i]>0)
		{
			printf("%d ", num[i]);
		}
	}
}

void imprimirNumerosNegativos(int num[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		if(num[i]<0)
		{
			printf("%d ", num[i]);
		}
	}
}

void ordenarArrayPositivos(int numArray[], int tam)
{
    int flagSwap;
    int buffer;
    int nuevoLimite;

    if(numArray != NULL && tam >=0)
    {
        nuevoLimite=tam-1;
        do
        {
            flagSwap=0;
            for(int i=0;i<nuevoLimite;i++)
            {
                if(numArray[i]>numArray[i+1])
                {
                    flagSwap=1;
                    buffer=numArray[i];
                    numArray[i]=numArray[i+1];
                    numArray[i+1]=buffer;
                }
            }
            nuevoLimite--;
        }while(flagSwap==1);
    }
}

void ordenarArrayNegativos(int numArray[], int tam)
{
	int flagSwap;
	int buffer;
	int nuevoLimite;

	if(numArray != NULL && tam >=0)
	{
		nuevoLimite=tam-1;
		do
		{
			flagSwap=0;
			for(int i=0;i<nuevoLimite;i++)
			{
				if(numArray[i]<numArray[i+1])
				{
					flagSwap=1;
					buffer=numArray[i];
					numArray[i]=numArray[i+1];
					numArray[i+1]=buffer;
				}
			}
			nuevoLimite--;
		}while(flagSwap==1);
	}
}
