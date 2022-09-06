/*
 ============================================================================
Cubilla Damian
Ejercicio 2-2:
Ingresar 10 números enteros, distintos de cero. Mostrar:
Cantidad de pares e impares.
El menor número ingresado.
De los pares el mayor número ingresado.
Suma de los positivos.
Producto de los negativos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int contPar=0;
	int contImpar=0;
	int numMenor;
	int mayorPar=0;
	int acuPositivos=0;
	int prodNegativos=1;
	for(int i=0;i<TAM;i++)
	{
		printf("Ingrese numero: ");
		scanf("%d", &numero);
		if(numero%2==0)
		{
			contPar++;
			if(numero>mayorPar)
			{
				mayorPar=numero;
			}
		}
		else
		{
			contImpar++;
		}

		if(i==0 || numero<numMenor)
		{
			numMenor=numero;
		}

		if(numero>0)
		{
			acuPositivos+=numero;
		}
		else
		{
			prodNegativos=prodNegativos*numero;
		}
	}

	printf("A. Cantidad de pares: %d - Cantidad de impares: %d\n", contPar, contImpar);
	printf("B. El menor numero ingresado es: %d\n", numMenor);
	printf("C. El mayor numero par es: %d\n", mayorPar);
	printf("D. La suma de los numero positivos: %d\n", acuPositivos);
	printf("E. El producto de los numeros negativos: %d\n", prodNegativos);
	return EXIT_SUCCESS;
}
