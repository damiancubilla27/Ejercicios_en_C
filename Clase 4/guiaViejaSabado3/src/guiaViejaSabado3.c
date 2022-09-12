/*
 ============================================================================
Cubilla Damian
Ejercicio 2-2:
Realizar un programa que permita el ingreso de 10 números enteros. Determinar el
promedio de los positivos, la cantidad de ceros y del menor de los negativos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void ingresarNumeros(int num[], int tam);
float promedioPositivo(int num[], int tam);
int cantidadCeros(int num[], int tam);
int menorNegativo(int num[], int tam);

int main(void) {
	setbuf(stdout, NULL);
	int numeros[10];
	float promedio;
	int ceros;
	int menor;

	ingresarNumeros(numeros, TAM);
	promedio=promedioPositivo(numeros, TAM);
	ceros=cantidadCeros(numeros, TAM);
	menor=menorNegativo(numeros, TAM);

	printf("El promedio de los numeros positivos es: %.2f\n", promedio);
	printf("La cantidad de ceros es: %d\n", ceros);
	printf("El menor de los negativos es: %d\n", menor);
	return EXIT_SUCCESS;
}

void ingresarNumeros(int num[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("Ingrese numero: ");
		scanf("%d", &num[i]);
	}
}

float promedioPositivo(int num[], int tam)
{
	int acumulador;
	int contador;
	float retorno;
	acumulador=0;
	contador=0;
	for(int i=0;i<tam;i++)
	{
		if(num[i]>0)
		{
			acumulador+=num[i];
			contador++;
		}
	}
	retorno=(float)acumulador/contador;
	return retorno;
}

int cantidadCeros(int num[], int tam)
{
	int retorno=0;
	for(int i=0;i<tam;i++)
	{
		if(num[i]==0)
		{
			retorno++;
		}
	}
	return retorno;
}

int menorNegativo(int num[], int tam)
{
	int retorno;
	int bandera=1;
	for(int i=0;i<tam;i++)
	{
		if(num[i]<0)
		{
			if(bandera==1 || num[i]<retorno)
			{
				retorno=num[i];
				bandera=0;
			}
		}

	}
	return retorno;
}
