/*
 ============================================================================
 Cubilla Damian
 Ejercicio 6:
 Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en qué orden fue ingresado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int maximo;
	int minimo;
	int ordenDeIngreMax;
	int ordenDeIngreMin;

	ordenDeIngreMax=0;
	ordenDeIngreMin=0;

	for(int i=0;i<5;i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &numero);

		if(i==0 || numero>maximo)
		{
			maximo=numero;
			ordenDeIngreMax=i+1;
		}

		if(i==0 || numero<minimo)
		{
			minimo=numero;
			ordenDeIngreMin=i+1;
		}
	}

	printf("El numero maximo es: %d - Orden: %d\n", maximo, ordenDeIngreMax);
	printf("El numero minimo es: %d - Orden: %d\n", minimo, ordenDeIngreMin);
	return EXIT_SUCCESS;
}
