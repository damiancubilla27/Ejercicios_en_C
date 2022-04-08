/*
 ============================================================================
Cubilla Damian
Ejercicio 5:
Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
a.El promedio de los números positivos.
b.El promedio de los números negativos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int validacion;
	int contaNumPos;
	int sumaPos;
	int contaNumNega;
	int sumaNega;
	float positivos;
	float negativos;

	contaNumPos=0;
	sumaPos=0;
	contaNumNega=0;
	sumaNega=0;

	do
	{
		printf("Ingresa un numero: ");
		scanf("%d", &numero);

		if(numero>0)
		{
			sumaPos=sumaPos+numero;
			contaNumPos++;
		}
		else
		{
			sumaNega=sumaNega+numero;
			contaNumNega++;
		}

		printf("Desea continuar? 1=Si 0=No : ");
		scanf("%d", &validacion);

	}while(validacion == 1);

	positivos=(float)sumaPos/contaNumPos;
	negativos=(float)sumaNega/contaNumNega;

	printf("a.El promedio de los numeros positivos es: %.1f\n", positivos);
	printf("b.El promedio de los numeros negativos es: %.1f\n", negativos);

	return EXIT_SUCCESS;
}
