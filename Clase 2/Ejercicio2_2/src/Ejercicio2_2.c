/*
 ============================================================================
Cubilla Damian
Ejercicio 2:
Se piden dos edades de tipo "int" al usuario y se pide el promedio.
Testear con dos edades consecutivas, ej: 7y8, 5y4, 20y21.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int edadUno;
	int edadDos;
	int suma;
	float promedio;

	printf("Ingrese una edad: ");
	fflush(stdin);
	scanf("%d", &edadUno);
	printf("Ingrese otra edad: ");
	fflush(stdin);
	scanf("%d", &edadDos);

	suma=edadUno+edadDos;
	promedio= (float)suma/2;

	printf("El promedio de edad es de: %.1f", promedio);

	return EXIT_SUCCESS;
}
