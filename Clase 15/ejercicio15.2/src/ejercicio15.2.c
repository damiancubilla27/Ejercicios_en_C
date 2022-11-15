/*
 ============================================================================
Cubilla Damian
Ejercicio 15-2:
Realizar una función que reciba como parámetro un puntero a entero.
La función le pedirá al usuario que cargue un valor por medio del puntero.
Retornará si pudo cargarlo o no.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pedirNumero(int* numero);

int main(void) {
	setbuf(stdout, NULL);
	int numero;


	if(pedirNumero(&numero)==0)
	{
		printf("Pudo cargar el numero y es %d\n", numero);
	}
	else
	{
		printf("No se pudo cargar el numero\n");
	}
	return EXIT_SUCCESS;
}

int pedirNumero(int* numero)
{
	int retorno=-1;

	if(numero!=NULL)
	{
		printf("Ingrese numero: ");
		scanf("%d", numero);
		retorno=0;
	}
	return retorno;
}
