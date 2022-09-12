/*
 ============================================================================
Cubilla Damian
Ejercicio 5-1:
Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5
void ingreseNumero(int num[], int tam);
void mostrarNumeros(int num[], int tam);
int sumatoriaNumeros(int num[], int tam);

int main(void) {
	setbuf(stdout, NULL);
	int numeros[TAM];
	int suma;
	ingreseNumero(numeros, TAM);
	mostrarNumeros(numeros, TAM);
	suma=sumatoriaNumeros(numeros, TAM);
	printf("\nLa suma de los numeros es: %d\n", suma);
	return EXIT_SUCCESS;
}

void ingreseNumero(int num[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("Ingrese numero: ");
		scanf("%d", &num[i]);
	}
}

void mostrarNumeros(int num[], int tam)
{
	printf("Numeros ingresados: ");
	for(int i=0;i<tam;i++)
	{
		printf("%d ", num[i]);
	}
}

int sumatoriaNumeros(int num[], int tam)
{
	int retorno=0;
	for(int i=0;i<tam;i++)
	{
		retorno+=num[i];
	}
	return retorno;
}
