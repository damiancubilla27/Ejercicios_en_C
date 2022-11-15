/*
 ============================================================================
Cubilla Damian
ANEXO 5-1:
Armar un Menú de Opciones con las siguientes opciones
1-Inicializar
2-Cargar
3-Mostrar
4-Calcular Promedio
5-Ordenar
Al ingresar a cada opción del menú deberá imprimir en pantalla el nombre del mismo.
Ej: Si se presiona la opción 1 mostrar por pantalla “Ud. ha seleccionado lo opción 1-Inicializar”

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int utn_getNumeroEntero(int* pNum, char* mensaje, char* mensajeError, int min, int max, int reintentos);

int main(void) {
	setbuf(stdout, NULL);
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

	return EXIT_SUCCESS;
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
