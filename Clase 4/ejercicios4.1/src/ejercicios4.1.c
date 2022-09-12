/*
 ============================================================================
Ejercicio 4-1:
Realizar un programa EN EL MAIN que permita calcular y mostrar el factorial de un número.
Utilizar la función PedirNumero de la ejercitación 3-4.
Por ejemplo:
5! = 5*4*3*2*1 = 120

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int IngresarEntero(void);

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int factorial=1;
	numero=IngresarEntero();

	for(int i=1;i<=numero;i++)
	{
		factorial=factorial*i;
	}

	printf("El factorial del numero %d es: %d ", numero, factorial);
	return EXIT_SUCCESS;
}

int IngresarEntero(void)
{
    int retorno;
    do{
        printf("Ingrese un numero: ");
        scanf("%d", &retorno);
    }while(retorno<0 || retorno>10);
    return retorno;
}
