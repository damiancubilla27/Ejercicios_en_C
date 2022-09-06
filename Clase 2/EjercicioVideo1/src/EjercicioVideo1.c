/*
 ============================================================================
Cubilla Damian
ejercicio 1:
Pedir 5 numeros y dar como resultado maximo y minimo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int maximo;
	int minimo;
	for(int i=0;i<TAM;i++)
	{
		printf("Ingrese numero: ");
		scanf("%d", &numero);

		if(i==0 || numero>maximo)
		{
			maximo=numero;
		}

		if(i==0 || numero<minimo)
		{
			minimo=numero;
		}
	}

	printf("El numero maximo es: %d - El numero minimo es: %d", maximo, minimo);
	return EXIT_SUCCESS;
}
