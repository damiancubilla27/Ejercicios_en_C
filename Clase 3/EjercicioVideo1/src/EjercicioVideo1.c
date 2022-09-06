/*
 ============================================================================
Cubilla Damian
ejercicio 1:
Un programa que pida al usuario ingresar dos numeros, y despues otro numero
para realizar una operacion matematica (sumar, restar, multiplicar, dividir)
para esos numeros.
Para aca operacion matematica se debera utilizar funciones y retornar el resultado
para mostrarlo en el main.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int SumarNumeros(int numeroUno, int numeroDos);
int RestarNumeros(int numeroUno, int numeroDos);
int MultiplicarNumeros(int numeroUno, int numeroDos);
float DividirNumeros(int numeroUno, int numeroDos);

int main(void) {
	setbuf(stdout, NULL);
	int numUno;
	int numDos;
	int operacion;
	int resultado;
	float resultadoDos;

	printf("Ingrese numero: ");
	scanf("%d", &numUno);
	printf("Ingrese otro numero: ");
	scanf("%d", &numDos);
	printf("1.SUMAR - 2.RESTAR - 3.MULTIPLICAR - 4.DIVIDIR: ");
	scanf("%d", &operacion);

	switch(operacion)
	{
		case 1:
			resultado = SumarNumeros(numUno, numDos);
			break;
		case 2:
			resultado = RestarNumeros(numUno, numDos);
			break;
		case 3:
			resultado = MultiplicarNumeros(numUno, numDos);
			break;
		case 4:
			resultadoDos = DividirNumeros(numUno, numDos);
			break;
	}

	if(operacion == 4)
	{
		printf("El resultado es: %.2f", resultadoDos);
	}
	else
	{
		printf("El resultado es: %d", resultado);
	}

	return EXIT_SUCCESS;
}

int SumarNumeros(int numeroUno, int numeroDos)
{
	int retornar;
	retornar=numeroUno+numeroDos;
	return retornar;
}

int RestarNumeros(int numeroUno, int numeroDos)
{
	int retornar;
	retornar=numeroUno-numeroDos;
	return retornar;
}

int MultiplicarNumeros(int numeroUno, int numeroDos)
{
	int retornar;
	retornar=numeroUno*numeroDos;
	return retornar;
}

float DividirNumeros(int numeroUno, int numeroDos)
{
	float retornar;
	if(numeroDos == 0)
	{
		retornar=0;
	}
	else
	{
		retornar=(float)numeroUno/numeroDos;
	}
	return retornar;
}
