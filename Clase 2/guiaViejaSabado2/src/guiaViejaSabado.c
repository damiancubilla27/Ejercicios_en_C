/*
 ============================================================================
Cubilla Damian
Ejercicio 1-2:
Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en qué orden
fue ingresado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int maximo;
	int minimo;
	int posiMax;
	int posiMin;
	for(int i=0;i<5;i++)
	{
		printf("Ingrese numero: ");
		scanf("%d", &numero);
		if(i==0 || numero>maximo)
		{
			maximo=numero;
			posiMax=i+1;
		}
		if(i==0 || numero<minimo)
		{
			minimo=numero;
			posiMin=i+1;
		}
	}
	printf("El numero maximo es %d - posicion %d\n", maximo, posiMax);
	printf("El numero minimo es %d - posicion %d\n", minimo, posiMin);
	return EXIT_SUCCESS;
}
