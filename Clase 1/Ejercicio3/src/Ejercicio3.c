/*
 ============================================================================
Cubilla Damian
Ejercicio 3:
Pedir N numeros (hasta que el usuario desee) y luego imprimir el promedio.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int numero;
	int acumulador=0;
	int contador=0;
	char respuesta = 's';
	float promedio;

	while(respuesta == 's')
	{
		printf("Ingrese numero: ");
		scanf("%d", &numero);
		contador++;
		acumulador+=numero;
		printf("Desea seguir ingresando numeros? ");
		fflush(stdin);
		//__fpurge(stdin);
		scanf("%c", &respuesta);
	}

	promedio = (float)acumulador/contador;
	printf("El promedio de los numeros es: %.2f", promedio);

	return EXIT_SUCCESS;
}
