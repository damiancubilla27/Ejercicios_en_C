/*
 ============================================================================
Cubilla Damian
Ejercicio 5-3:
Realizar un programa que permita el ingreso de 10 números enteros distintos de cero.
La carga deberá ser aleatoria (todos los elementos se inicializan en cero por default).
Determinar el promedio de los positivos, y del menor de los negativos la suma de los
antecesores (Según la recta numérica de los reales, hasta llegar a cero).
Utilizar funciones y vectores.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void inicializarVector(int num[], int tam);
void cargaAletoriaVector(int num[], int tam);
void imprimirNumeros(int num[], int tam);
int buscarPositivos(int num[], int tam);
float cantidadPositivos(int num[], int tam);
int buscarElMenorNegativo(int num[], int tam);
int sumatoriaDeLosNegativos(int num[], int tam);

int main(void) {
	setbuf(stdout, NULL);
	int numero[TAM];
	int numPosi;
	float prom;
	int numNega;
	int sumaNega;

	inicializarVector(numero, TAM);
	cargaAletoriaVector(numero, TAM);
	imprimirNumeros(numero, TAM);
	numPosi=buscarPositivos(numero, TAM);
	if(numPosi==0)
	{
		printf("\nNo se ingresaron numeros positivos!\n");
	}
	else
	{
		prom=cantidadPositivos(numero, TAM);
		printf("\nEl promedio de los numeros positivos es: %.2f\n", prom);
	}

	numNega=buscarElMenorNegativo(numero, TAM);
	sumaNega=sumatoriaDeLosNegativos(numero, TAM);

	if(numNega==0)
	{
		printf("Nose ingresaron numeros negativos!\n");
	}
	else
	{
		printf("El menor de los numeros negativos es: %d y la sumatoria de sus antecesores es: %d\n ", numNega, sumaNega);
	}


	return EXIT_SUCCESS;
}

void inicializarVector(int num[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		num[i]=0;
	}
}

void cargaAletoriaVector(int num[], int tam)
{
	int numero;
	int posicion;
	char seguir;
	do{
		printf("Ingrese numero: ");
		scanf("%d", &numero);
		printf("Ingrese posicion (de 1 hasta 10): ");
		scanf("%d", &posicion);

		num[posicion-1]=numero;

		printf("Desea continuar s/n: ");
		fflush(stdin);
		scanf("%c", &seguir);
	}while(seguir=='s');
}

void imprimirNumeros(int num[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("%d ", num[i]);
	}
}

int buscarPositivos(int num[], int tam)
{
	int retorno=0;
	for(int i=0;i<tam;i++)
	{
		if(num[i]>0)
		{
			retorno++;
		}
	}
	return retorno;
}

float cantidadPositivos(int num[], int tam)
{
	int contador;
	int acumulador;
	float promedio;

	contador=0;
	acumulador=0;
	for(int i=0;i<tam;i++)
	{
		if(num[i]>0)
		{
			contador++;
			acumulador+=num[i];
		}
	}
	promedio=(float)acumulador/contador;
	return promedio;
}

int buscarElMenorNegativo(int num[], int tam)
{
	int retorno=0;
	int bandera=1;
	for(int i=0;i<tam;i++)
	{
		if(bandera==1)
		{
			retorno=num[i];
			bandera=0;
		}
		else
		{
			if(num[i]<retorno)
			{
				retorno=num[i];
			}
		}
	}
	return retorno;
}

int sumatoriaDeLosNegativos(int num[], int tam)
{
	int numero;
	int retorno=0;
	for(int i=0;i<tam;i++)
	{
		if(num[i]<0 || num[i]<numero)
		{
			numero=num[i];
			retorno+=num[i];
		}
	}
	return retorno;
}
