/*
 ============================================================================
Cubilla Damian
Ejercicio 3-5:
Realizar un programa en donde se puedan utilizar los prototipos de la función Sumar en sus 4 combinaciones.
int Sumar1(int, int);
int Sumar2(void);
void  Sumar3(int, int);
void Sumar4(void);
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int Sumar1(int, int);
int Sumar2(void);
void  Sumar3(int, int);
void Sumar4(void);

int main(void) {
	setbuf(stdout, NULL);
	int numeroUno;
	int numeroDos;
	int resultadoUno;
	int resultadoDos;
	//Uno
	printf("Ingrese numero: ");
	scanf("%d", &numeroUno);
	printf("Ingrese numero: ");
	scanf("%d", &numeroDos);
	resultadoUno=Sumar1(numeroUno, numeroDos);
	printf("El resultado es: %d\n", resultadoUno);
	//Dos
	resultadoDos=Sumar2();
	printf("El resultado es: %d\n", resultadoDos);
	//Tres
	Sumar3(numeroUno, numeroDos);
	//Cuatro
	Sumar4();
	return EXIT_SUCCESS;
}

int Sumar1(int numUno, int numDos)
{
	int retorno;
	retorno=numUno+numDos;
	return retorno;
}
int Sumar2(void)
{
	int numeroUno;
	int numeroDos;
	int resultadoDos;
	printf("Ingrese numero: ");
	scanf("%d", &numeroUno);
	printf("Ingrese numero: ");
	scanf("%d", &numeroDos);
	resultadoDos=numeroUno+numeroDos;
	return resultadoDos;
}
void  Sumar3(int numUno, int numDos)
{
	int retorno;
	retorno=numUno+numDos;
	printf("El resultado es: %d\n", retorno);
}
void Sumar4(void)
{
	int numeroUno;
	int numeroDos;
	int resultadoCuatro;
	printf("Ingrese numero: ");
	scanf("%d", &numeroUno);
	printf("Ingrese numero: ");
	scanf("%d", &numeroDos);
	resultadoCuatro=numeroUno+numeroDos;
	printf("El resultado es: %d\n", resultadoCuatro);
}
