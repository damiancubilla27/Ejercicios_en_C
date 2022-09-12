/*
 ============================================================================
Cubilla Damian
Ejercicio 5-2:
Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
A. Cantidad de positivos y negativos.
B. Sumatoria de los pares.
C. El mayor de los impares.
D. Listado de los números ingresados.
E. Listado de los números pares.
F. Listado de los números de las posiciones impares.
Anexo 5-2
G. Los números que se repiten
H. Los positivos creciente y los negativos de manera decreciente
Se deberán utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 10
void pedirNumeros(int num[], int tam);
void validarNumeros(int num[], int tam, int min, int max);
int cantidadPositivos(int num[], int tam);
int cantidadNegativos(int num[], int tam);
int sumarPares(int num[], int tam);
int sacarMayorImpar(int num[], int tam);
void imprimirNumeros(int num[], int tam);
void listadoPares(int num[], int tam);
void listadoPosicionesImpares(int num[], int tam);
void listadoNumerosCreciente(int num[], int tam);
void listadoNumerosDecreciente(int num[], int tam);
void numerosRepetidos(int num[], int tam);

int main(void) {
	setbuf(stdout, NULL);
	int numeros[TAM];
	int positivos;
	int negativos;
	int sumaPares;
	int mayorImpar;

	pedirNumeros(numeros, TAM);
	validarNumeros(numeros, TAM, -1000, 1000);
	positivos=cantidadPositivos(numeros, TAM);
	negativos=cantidadNegativos(numeros, TAM);
	sumaPares=sumarPares(numeros, TAM);
	mayorImpar=sacarMayorImpar(numeros, TAM);

	printf("A. Cantidad de positivos es: %d y negativos es: %d\n", positivos, negativos);
	printf("B. Sumatoria de los pares: %d\n", sumaPares);
	printf("C. El mayor de los impares es: %d\n", mayorImpar);
	printf("D. Listado de los números ingresados: ");
	imprimirNumeros(numeros, TAM);
	printf("\nE. Listado de los números pares: ");
	listadoPares(numeros, TAM);
	printf("\nF. Listado de los números de las posiciones impares: ");
	listadoPosicionesImpares(numeros, TAM);
	printf("\nG. Los números que se repiten: ");
	numerosRepetidos(numeros, TAM);
	printf("\nH. Listado de los números ingresados creciente: ");
	listadoNumerosCreciente(numeros, TAM);
	imprimirNumeros(numeros, TAM);
	printf("\nH. Listado de los números ingresados decreciente: ");
	listadoNumerosDecreciente(numeros, TAM);
	imprimirNumeros(numeros, TAM);


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

void validarNumeros(int num[], int tam, int min, int max)
{
	for(int i=0;i<tam;i++)
	{
		if(num[i]<min|| num[i]>max)
		{
			do
			{
				printf("Reingrese numero: ");
				scanf("%d", &num[i]);

			}while(num[i]<min || num[i]>max);
		}
	}
}

int cantidadPositivos(int num[], int tam)
{
	int retorno;
	retorno=0;
	for(int i=0;i<tam;i++)
	{
		if(num[i]>0)
		{
			retorno++;
		}
	}
	return retorno;
}

int cantidadNegativos(int num[], int tam)
{
	int retorno;
	retorno=0;
	for(int i=0;i<tam;i++)
	{
		if(num[i]<0)
		{
			retorno++;
		}
	}
	return retorno;
}

int sumarPares(int num[], int tam)
{
	int retorno;
	retorno=0;
	for(int i=0;i<tam;i++)
	{
		if(num[i]%2==0)
		{
			retorno+=num[i];
		}
	}
	return retorno;
}

int sacarMayorImpar(int num[], int tam)
{
	int retorno;
	int bandera=1;
	for(int i=0;i<tam;i++)
	{
		if(num[i]%2!=0)
		{
			if(bandera==1 || num[i]>retorno)
			{
				retorno=num[i];
				bandera=0;
			}
		}
	}
	return retorno;
}

void imprimirNumeros(int num[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("%d ", num[i]);
	}
}

void listadoPares(int num[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		if(num[i]%2==0)
		{
			printf("%d ", num[i]);
		}
	}
}

void listadoPosicionesImpares(int num[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		if(i%2==0)
		{
			printf("%d ", num[i]);
		}
	}
}

void listadoNumerosCreciente(int num[], int tam)
{
	int aux;
	for(int i=0;i<tam-1;i++)
	{
		for(int j=i+1;j<tam;j++)
		{
			if(num[i]>num[j])
			{
				aux=num[i];
				num[i]=num[j];
				num[j]=aux;
			}
		}
	}
}

void listadoNumerosDecreciente(int num[], int tam)
{
	int aux;
	for(int i=0;i<tam-1;i++)
	{
		for(int j=i+1;j<tam;j++)
		{
			if(num[i]<num[j])
			{
				aux=num[i];
				num[i]=num[j];
				num[j]=aux;
			}
		}
	}
}

void numerosRepetidos(int num[], int tam)
{
	for(int i=0;i<tam-1;i++)
	{
		for(int j=i+1;j<tam;j++)
		{
			if(num[i]==num[j])
			{
				printf("%d ", num[i]);
			}
		}
	}
}
