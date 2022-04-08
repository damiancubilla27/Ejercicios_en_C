/*
 ============================================================================
 Cubilla Damian
 Ejercicio 3:
 Se ingresan 10 personas con el inicial del nombre y edad.
 Informar la suma, el promedio, el mayor y el menor.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define PERSONAS 10

int main(void) {
	setbuf(stdout, NULL);
	char nombreInicial;
	int edad;
	int suma;
	float promedio;
	int mayor;
	int menor;
	char mayorLetra;
	char menorLetra;

	suma=0;

	for(int i=0;i<PERSONAS;i++)
	{
		printf("Ingrese el inicial de su nombre: ");
		fflush(stdin);
		scanf("%c", &nombreInicial);
		printf("Ingrese su edad: ");
		fflush(stdin);
		scanf("%d", &edad);

		suma=suma+edad;

		if(i==0 || edad>mayor)
		{
			mayor=edad;
			mayorLetra=nombreInicial;
		}

		if(i==0 || edad<menor)
		{
			menor=edad;
			menorLetra=nombreInicial;
		}
	}

	promedio=(float)suma/PERSONAS;
	printf("1.La suma de las edades es: %d\n", suma);
	printf("2.El promedio de las edades es: %.1f\n", promedio);
	printf("3.El mayor es %c con %d años!\n", mayorLetra, mayor);
	printf("4.El menor es %c con %d años!!\n", menorLetra, menor);

	return EXIT_SUCCESS;
}
