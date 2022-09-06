/*
 ============================================================================
Cubilla Damian
Ejercicio 1-3: ingresar 3 números y mostrar el número del medio, sólo si existe.
En caso de que no exista también informarlo.
Ejemplo:
1   5   3     el 3 es del medio//
5   1   5    no hay numero del medio
3  5   1     el 3 es del medio
3   1   5    el 3 es del medio//
5   3   1    el 3 es del medio

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
	if((numeroUno>numeroDos && numeroUno<numeroTres) || (numeroUno<numeroDos && numeroUno>numeroTres))
	{
		printf("El %d es del medio", numeroUno);
	}
	if((numeroDos>numeroUno && numeroDos<numeroTres) || (numeroDos<numeroUno && numeroDos>numeroTres))
	{
		printf("El %d es del medio", numeroDos);
	}
	if((numeroTres>numeroUno && numeroTres<numeroDos) || (numeroTres<numeroUno && numeroTres>numeroDos))
	{
		printf("El %d es del medio", numeroTres);
	}
	if(numeroUno == numeroDos || numeroUno == numeroTres || numeroDos == numeroTres)
	{
		printf("no hay numero del medio");
	}
	return EXIT_SUCCESS;
}
