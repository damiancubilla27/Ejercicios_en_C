/*
 ============================================================================
Cubilla Damian
Ejercicio 2:
Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en qué orden fue ingresado.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void CalcularMinMax(int *num, char *mensaje, int tam, int *numMax, int *numMin, int *ordMax, int *ordMin);

int main(void) {
	setbuf(stdout, NULL);
	int numeros[TAM];
	int numeroMax;
	int numeroMin;
	int ordenMax;
	int ordenMin;

	CalcularMinMax(numeros, "Ingrese numero: ", TAM, &numeroMax, &numeroMin, &ordenMax, &ordenMin);

	printf("El numero maximo es %d y su orden de ingreso es %d\n", numeroMax, ordenMax);
	printf("El numero minimo es %d y su orden de ingreso es %d\n", numeroMin, ordenMin);
	return EXIT_SUCCESS;
}

void CalcularMinMax(int *num, char *mensaje, int tam, int *numMax, int *numMin, int *ordMax, int *ordMin)
{
	int numeroMaximo;
	int numeroMinimo;
	int ordenMaxima;
	int ordenMinima;
	for (int i = 0; i < tam; i++)
	{
		printf("%s", mensaje);
		scanf("%d", &num[i]);
		if(i==0 || num[i]>numeroMaximo)
		{
			numeroMaximo=num[i];
			ordenMaxima=i+1;
		}

		if(i==0 || num[i]<numeroMinimo)
		{
			numeroMinimo=num[i];
			ordenMinima=i+1;
		}
	}
	*numMax=numeroMaximo;
	*numMin=numeroMinimo;
	*ordMax=ordenMaxima;
	*ordMin=ordenMinima;

	for (int i = 0; i < TAM; i++)
	{
		printf("Numero: %d\n", num[i]);
	}
}
