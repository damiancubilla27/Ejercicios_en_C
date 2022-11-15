/*
 ============================================================================
Cubilla Damian
Se ingresan 10 numeros en un array/vector, validar entre 0 y 20
ingresados por el usuario en la forma secuecial.
Mostrar:
a- La cantidad que coinciden con el numero maximo y sus indices.
b- La cantidad que coninciden con el numero minimo y sus indices.
c- Luego solo mostrar los elementos con sus indices que superen el numero 10.
d- Mostrar el listado de numero completo.
e- Mostrar los elementos mayores a 17 o menos a 3.
f- Mostrar el promedio de todos los numeros ingresados.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "videoGerman.h"
#define TAM 5

int main(void) {
	setbuf(stdout, NULL);
	int numeros[TAM];
	int numMaximo;
	int cantMaximo;
	int numMinimo;
	int cantMinimo;
	float promedio;

	ingresarNumeros(numeros, TAM);
	validarNumeros(numeros, TAM);

	numMaximo=buscarNumeroMaximo(numeros, TAM);
	cantMaximo=coincidirNumero(numeros, TAM, numMaximo);
	printf("a. El numero maximo es: %d y aparece %d - indice: ", numMaximo, cantMaximo);
	imprimirIndices(numeros, TAM, numMaximo);

	numMinimo=buscarNumeroMinimo(numeros, TAM);
	cantMinimo=coincidirNumero(numeros, TAM, numMinimo);
	printf("\nb. El numero minimo es: %d y aparece %d - indice: ", numMinimo, cantMinimo);
	imprimirIndices(numeros, TAM, numMinimo);

	esMayorADiez(numeros, TAM);
	mostrarArray(numeros, TAM);
	mostrarMenorMayorQue(numeros, TAM);

	promedio=promedioNumeros(numeros, TAM);
	printf("\nf. El promedio de los numeros es: %.2f", promedio);

	return EXIT_SUCCESS;
}


