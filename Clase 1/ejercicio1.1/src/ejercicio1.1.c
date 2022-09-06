/*
 ============================================================================
 Name        : 1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numeroUno;
	int numeroDos;
	int suma;

	printf("Ingrese un numero entero: ");
	scanf("%d", &numeroUno);
	printf("Ingrese otro numero entero: ");
	scanf("%d", &numeroDos);

	suma= numeroUno+numeroDos;

	printf("La suma entre %d y %d da como resultado %d", numeroUno, numeroDos, suma);
	return EXIT_SUCCESS;
}
