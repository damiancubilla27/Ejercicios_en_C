/*
 ============================================================================
Cubilla Damian
Pedir numeros hasta que el usuario ingrese 888, y dar como resultado maximo y minimo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int respuesta;
	int flag=1;
	int maximo;
	int minimo;
	do{
		printf("Ingrese numero: ");
		scanf("%d", &numero);
		if(flag==1)
		{
			maximo=numero;
			minimo=numero;
			flag=0;
		}
		if(numero>maximo)
		{
			maximo=numero;
		}
		if(numero<minimo)
		{
			minimo=numero;
		}
		printf("Desea continuar? (Si=1 - No=888)");
		scanf("%d", &respuesta);
	}while(respuesta!=888);
	printf("El numero maximo es: %d - El numero minimo es: %d", maximo, minimo);
	return EXIT_SUCCESS;
}
