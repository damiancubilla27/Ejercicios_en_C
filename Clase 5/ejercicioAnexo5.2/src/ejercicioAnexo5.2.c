/*
 ============================================================================
Cubilla Damian
ANEXO 5-2:
Realizar un programa que desde el main llame o invoque a la función que
muestre el Menú del punto anterior.
Utilizar funciones y bibliotecas.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int utn_getNumeroEntero(int* pNum, char* mensaje, char* mensajeError, int min, int max, int reintentos);
void invocarMenu(void);
int main(void) {
	setbuf(stdout, NULL);
	invocarMenu();

	return EXIT_SUCCESS;
}

void invocarMenu(void)
{
	int opcion;

	do
	{
		if(utn_getNumeroEntero(&opcion, "1-Inicializar\n2-Cargar\n3-Mostrar\n4-Calcular Promedio\n5-Ordenar\n6-Salir\nIngrese opcion: ", "Error\n", 1, 6, 2)==0)
		{
			switch(opcion)
			{
			case 1:
				printf("Ud. ha seleccionado lo opción 1-Inicializar \n");
				break;
			case 2:
				printf("Ud. ha seleccionado lo opción 2-Cargar \n");
				break;
			case 3:
				printf("Ud. ha seleccionado lo opción 3-Mostrar \n");
				break;
			case 4:
				printf("Ud. ha seleccionado lo opción 4-Calcular Promedio \n");
				break;
			case 5:
				printf("Ud. ha seleccionado lo opción 5-Ordenar \n");
				break;
			}
		}
		else
		{
			printf("Lo sentimos no podemos seguir operando!\n");
			opcion=6;
		}

	}while(opcion!=6);
}

int utn_getNumeroEntero(int* pNum, char* mensaje, char* mensajeError, int min, int max, int reintentos)
{
    int bufferInt;
    int retorno=-1;
    if(pNum != NULL && mensaje != NULL && mensajeError !=NULL && min<=max && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%d", &bufferInt);
            if(bufferInt>=min && bufferInt<=max)
            {
                *pNum=bufferInt;
                retorno=0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}
