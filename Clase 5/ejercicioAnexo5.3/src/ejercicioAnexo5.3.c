/*
 ============================================================================
Cubilla Damian
ANEXO 5-3:
Crear un Array de 5 elementos de tipo numérico donde se cargarán edades.
Agregar la funcionalidad para la opción 1 del Menú del ejercicio anterior utilizando funciones,
es decir una función que inicialice el Array.
Agregar la funcionalidad para la opción 2 del Menú utilizando funciones,
es decir una función que le pida los números o edades al usuario para cargar el
Array de forma secuencial.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int utn_getNumeroEntero(int* pNum, char* mensaje, char* mensajeError, int min, int max, int reintentos);
void invocarMenu(void);
void inicializarArray(int arrayNum[], int tam);
void cargarSecuencial(int arrayNum[], int tam);

int main(void) {
	setbuf(stdout, NULL);
	invocarMenu();

	return EXIT_SUCCESS;
}

void invocarMenu(void)
{
	int opcion;
	int arrayNumeros[5];
	do
	{
		if(utn_getNumeroEntero(&opcion, "1-Inicializar\n2-Cargar\n3-Mostrar\n4-Calcular Promedio\n5-Ordenar\n6-Salir\nIngrese opcion: ", "Error\n", 1, 6, 2)==0)
		{
			switch(opcion)
			{
			case 1:
				printf("Ud. ha seleccionado lo opción 1-Inicializar \n");
				inicializarArray(arrayNumeros, TAM);
				break;
			case 2:
				printf("Ud. ha seleccionado lo opción 2-Cargar \n");
				cargarSecuencial(arrayNumeros, TAM);
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

void inicializarArray(int arrayNum[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		arrayNum[i]=0;
	}
}

void cargarSecuencial(int arrayNum[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("Ingrese edad: ");
		scanf("%d", &arrayNum[i]);
	}
}
