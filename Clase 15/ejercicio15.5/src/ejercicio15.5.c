/*
 ============================================================================
Cubilla Damian
Ejercicio 15-5
Escriba una función que reciba dos números enteros y los devuelva ordenados.
Es decir que en el primer parámetro debe devolver el menor valor
y en el 2do. el mayor.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void mayorYMenor(int* numUno, int* numDos);

int main(void) {
	setbuf(stdout, NULL);
	int numeroUno=13;
	int numeroDos=5;

	mayorYMenor(&numeroUno, &numeroDos);
	printf("El menor es %d y el mayor es %d\n", numeroUno, numeroDos);

	return EXIT_SUCCESS;
}

void mayorYMenor(int* numUno, int* numDos)
{
	int aux;

	if(numDos<numUno)
	{
		aux=*numUno;
		*numUno=*numDos;
		*numDos=aux;
	}

}
