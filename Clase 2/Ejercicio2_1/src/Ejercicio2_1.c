/*
 ============================================================================
Cubilla Damian
Ejercicio 1:
Pedir 10 numeros al usuario
Mostrar el maximo y minimo a medida que se ingresan los numeros.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int numero;
	int numeroMaximo;
	int numeroMinimo;

	for(int i=0;i<10;i++)
	{
		printf("Ingrese numero: ");
		fflush(stdin);
		scanf("%d", &numero);

		if(i==0 || numero>numeroMaximo)
		{
			numeroMaximo=numero;
			printf("Ahora el numero maximo es: %d\n", numero);
		}

		if(i==0 || numero<numeroMinimo)
		{
			numeroMinimo=numero;
			printf("Ahora el numero minimo es: %d\n", numero);
		}
	}

	printf("El numero maximo es: %d\n", numeroMaximo);
	printf("El numero minimo es: %d\n", numeroMinimo);
	return EXIT_SUCCESS;
}
