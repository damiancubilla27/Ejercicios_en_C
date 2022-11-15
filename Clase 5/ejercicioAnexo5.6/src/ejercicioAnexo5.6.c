/*
 ============================================================================
 Cubilla Damian
 ANEXO 5-6:
Realizar una función que calcule el promedio de los números ingresados en el Array
y agregarlo a la opción de Menú 4. La misma deberá imprimir el resultado por pantalla.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int utn_getNumeroEntero(int* pNum, char* mensaje, char* mensajeError, int min, int max, int reintentos);
void invocarMenu(void);
void inicializarArray(int arrayNum[], int tam);
//void cargarSecuencial(int arrayNum[], int tam);
void cargaAletoriaVector(int num[], int tam);
void imprimirNumeros(int num[], int tam);
float promedioNumeros(int num[], int tam);

int main(void) {
	setbuf(stdout, NULL);
	invocarMenu();

	return EXIT_SUCCESS;
}

void invocarMenu(void)
{
	int opcion;
	int arrayNumeros[5];
	float promedio;
	do
	{
		if(utn_getNumeroEntero(&opcion, "\n1-Inicializar\n2-Cargar\n3-Mostrar\n4-Calcular Promedio\n5-Ordenar\n6-Salir\nIngrese opcion: ", "Error\n", 1, 6, 2)==0)
		{
			switch(opcion)
			{
			case 1:
				printf("Ud. ha seleccionado lo opción 1-Inicializar \n");
				inicializarArray(arrayNumeros, TAM);
				break;
			case 2:
				printf("Ud. ha seleccionado lo opción 2-Cargar \n");
				cargaAletoriaVector(arrayNumeros, TAM);
				break;
			case 3:
				printf("Ud. ha seleccionado lo opción 3-Mostrar \n");
				imprimirNumeros(arrayNumeros, TAM);
				break;
			case 4:
				printf("Ud. ha seleccionado lo opción 4-Calcular Promedio \n");
				promedio=promedioNumeros(arrayNumeros, TAM);
				printf("El promedio de los numeros es: %.2f", promedio);
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

/*
void cargarSecuencial(int arrayNum[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("Ingrese edad: ");
		scanf("%d", &arrayNum[i]);
	}
}
*/

void cargaAletoriaVector(int num[], int tam)
{
	int numero;
	int posicion;
	char seguir;
	do{
		printf("Ingrese edad: ");
		scanf("%d", &numero);
		printf("Ingrese posicion(de 1 hasta 5): ");
		scanf("%d", &posicion);

		num[posicion-1]=numero;

		printf("Desea continuar s/n: ");
		fflush(stdin);
		scanf("%c", &seguir);
	}while(seguir=='s');
}

void imprimirNumeros(int num[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("%d ", num[i]);
	}
}

float promedioNumeros(int num[], int tam)
{
	float retorno;
	int acumulador;
	acumulador=0;
	for(int i=0;i<tam;i++)
	{
		acumulador+=num[i];
	}
	retorno=(float)acumulador/tam;
	return retorno;
}
