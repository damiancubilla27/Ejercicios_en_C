/*
 ============================================================================
Ejercicio 4-2:
Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit ,
validando que las temperaturas ingresadas estén entre el punto de congelación y
ebullición del agua para cada tipo de escala.
Las validaciones se hacen en una biblioteca.
Las funciones de transformación de fahrenheit a celsius y
de celsius a fahrenheit se hacen en otra biblioteca.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"
#include "transformacion.h"


int main(void) {
	setbuf(stdout, NULL);
	int celsius;
	int fahrenheit;
	int celsiusAFah;
	int fahACelsius;

	celsius=IngresarCelsius();
	fahrenheit=IngresarFahrenheit();
	celsiusAFah=celsiusAFahrenheit(celsius);
	fahACelsius=fahrenheitACelsius(fahrenheit);

	printf("Celsius a Fahrenheit : %d\n", celsiusAFah);
	printf("Fahrenheit a Celsius : %d\n", fahACelsius);

	return EXIT_SUCCESS;
}

