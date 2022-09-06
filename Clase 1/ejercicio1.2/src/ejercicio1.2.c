/*
 ============================================================================
Cubilla Damian
Ejercicio 1-2:
ingresar 3 números y mostrar cuál de los tres es el mayor.
Ejemplo:
Si ingresamos 5, 9 y 3 el programa mostrará: “El mayor de los números es el segundo”

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numeroUno;
	int numeroDos;
	int numeroTres;
	printf("Ingrese numero: ");
	scanf("%d", &numeroUno);
	printf("Ingrese numero: ");
	scanf("%d", &numeroDos);
	printf("Ingrese numero: ");
	scanf("%d", &numeroTres);
	if(numeroUno>numeroDos && numeroUno>numeroTres)
	{
		printf("El mayor de los numeros es el primero");
	}
	if(numeroDos>numeroUno && numeroDos>numeroTres)
	{
		printf("El mayor de los numeros es el segundo");
	}
	if(numeroTres>numeroUno && numeroTres>numeroDos)
	{
		printf("El mayor de los numeros es el tercero");
	}
	return EXIT_SUCCESS;
}
