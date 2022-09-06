/*
 ============================================================================
Cubilla Damian
Ejercicio 2-4:
Ingresar 5 caracteres e informar cuantas letras p (minúsculas) se ingresaron.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main(void) {
	setbuf(stdout, NULL);
	char caracter;
	int contadorP=0;
	for(int i=0;i<TAM;i++)
	{
		printf("Ingrese un caracter: ");
		fflush(stdin);
		scanf("%c", &caracter);

		if(caracter == 'p')
		{
			contadorP++;
		}
	}
	printf("La cantidad de p ingresasas son: %d", contadorP);
	return EXIT_SUCCESS;
}
