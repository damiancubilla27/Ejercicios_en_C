/*
 ============================================================================
Cubilla Damian
Ejercicio 3-4:
Especializar la función anterior para que permita validar el entero ingresado en un rango determinado.
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
	while(retorno<0 || retorno>100)
	{
		printf("Reingrese un numero: ");
		scanf("%d", &retorno);
	}
	return retorno;
}
