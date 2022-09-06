/*
 ============================================================================
Cubilla Damian
Ejercicio 1-1:
Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
a) El promedio de los números positivos.
b) El promedio de los números negativos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	char respuesta;
	int contaPar=0;
	int acumulaPar=0;
	int contaImpar=0;
	int acumulaImpar=0;
	float promedioPar;
	float promedioImpar;

	do{
		printf("Ingrese un numero: ");
		scanf("%d", &numero);
		if(numero%2==0)
		{
			contaPar++;
			acumulaPar+=numero;
		}
		else
		{
			contaImpar++;
			acumulaImpar+=numero;
		}
		printf("Desea continuar? (s/n): ");
		fflush(stdin);
		scanf("%c", &respuesta);
	}while(respuesta!='n');

	promedioPar=(float)acumulaPar/contaPar;
	promedioImpar=(float)acumulaImpar/contaImpar;
	printf("Promedio de numeros pares: %.2f\n", promedioPar);
	printf("Promedio de numeros impares: %.2f\n", promedioImpar);
	return EXIT_SUCCESS;
}
