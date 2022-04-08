/*
 ============================================================================
Cubilla Damian
Ejercicio 4:
Pedir numeros hasta que el usuario quiera (para cancelar 888) y dar como resultado maximo y minimo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int validacion;
	int numMaximo;
	int numMinimo;
	int bandera;

	bandera=1;

	do
	{
		printf("Ingresa un numero: ");
		scanf("%d", &numero);

		if(bandera==1 || numero>numMaximo)
		{
			numMaximo=numero;
		}

		if(bandera==1 || numero<numMinimo)
		{
			numMinimo=numero;
			bandera=0;
		}

		printf("Desea continuar? El caso de que no ingrese 888 : ");
		scanf("%d", &validacion);
	}while(validacion != 888);

	printf("El numero maximo es: %d\n", numMaximo);
	printf("El numero minimo es: %d\n", numMinimo);

	return EXIT_SUCCESS;
}
