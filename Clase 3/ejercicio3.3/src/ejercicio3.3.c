/*
 ============================================================================
Cubilla Damian
Ejercicio 3-3:
Crear una función que pida el ingreso de un entero y lo retorne.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int PedirNumero(void);

int main(void) {
	setbuf(stdout, NULL);
	int resultado;
	resultado = PedirNumero();
	printf("El numero ingresado es: %d", resultado);
	return EXIT_SUCCESS;
}

int PedirNumero(void)
{
	int retorno;
	printf("Ingrese un numero: ");
	scanf("%d", &retorno);
	return retorno;
}
