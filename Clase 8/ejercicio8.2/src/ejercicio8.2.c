/*
 ============================================================================
Cubilla Damian
Una empresa importadora que comercializa productos Apple, decide registrar de
sus productos los siguientes datos:
- idProducto (numerico)
- descripcion (alfanumérico)
- nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
- tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
- precio (numérico decimal)
Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
1. ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio
disponible en el array.
2. BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista,
dejando espacio disponible para un nuevo producto.
3. MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio
o el tipo.
4. LISTADO Productos.
5. LISTADO ordenado por precio.
6. LISTADO ordenado por descripción.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3
#define LIBRE 1
#define OCUPADO 0
#define EEUU 1
#define CHINA 2
#define OTRO 3
#define IPHONE 1
#define MAC 2
#define IPAD 3
#define ACCESORIOS 4

typedef struct
{
	int idproducto;
	char descripcion[11];
	int nacionalidad;
	int tipo;
	float precio;
	int estado;
}eProducto;

int utn_getNumeroEntero(int* pNum, char* mensaje, char* mensajeError, int min, int max, int reintentos);
eProducto ingresoDeUnSoloProducto(void);
void cargarProductos(eProducto unProducto[], int tam);
void inicializarArray(eProducto unProducto[], int tam);
void borrarProducto(eProducto unProducto[], int tam);
void modificarProducto(eProducto unProducto[], int tam);
void listarTodosLosProductos(eProducto unProducto[], int tam);
void listarPorPrecio(eProducto unProducto[], int tam);
void listarPorDescripcion(eProducto unProducto[], int tam);

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	eProducto arrayProductos[TAM];

	inicializarArray(arrayProductos, TAM);

	do
	{
		if(utn_getNumeroEntero(&opcion, "1.ALTA Producto\n2.BAJA Producto\n3.MODIFICACION Producto\n4.LISTADO Productos\n5.LISTADO ordenado por precio\n6.LISTADO ordenado por descripción\n7.Salir\nIngrese opcion: ", "Error\n", 1, 7, 3)==0)
		{
			switch(opcion)
			{
			case 1:
				cargarProductos(arrayProductos, TAM);
				break;
			case 2:
				borrarProducto(arrayProductos, TAM);
				break;
			case 3:
				modificarProducto(arrayProductos, TAM);
				break;
			case 4:
				listarTodosLosProductos(arrayProductos, TAM);
				break;
			case 5:
				listarPorPrecio(arrayProductos, TAM);
				listarTodosLosProductos(arrayProductos, TAM);
				break;
			case 6:
				listarPorDescripcion(arrayProductos, TAM);
				listarTodosLosProductos(arrayProductos, TAM);
				break;
			}
		}
		else
		{
			printf("\nNo es valido!!");
			opcion=7;
		}

	}while(opcion!=7);

	return EXIT_SUCCESS;
}

int utn_getNumeroEntero(int* pNum, char* mensaje, char* mensajeError, int min, int max, int reintentos)
{
    int bufferInt;
    int retorno = -1;
    while(reintentos>=0)
    {
        printf("%s",mensaje);
        scanf("%d", &bufferInt);
		if(bufferInt >= min && bufferInt <= max)
		{
			*pNum = bufferInt;
			retorno = 0;
			break;
		}
        printf("%s",mensajeError);
        reintentos--;
    }
    return retorno;
}

eProducto ingresoDeUnSoloProducto(void)
{
	eProducto eRetorno;
	printf("Ingrese descripcion del producto: ");
	fflush(stdin);
	scanf("%[^\n]", eRetorno.descripcion);
	printf("Ingrese nacionalidad EEUU 1 - CHINA 2 - OTRO 3: ");
	scanf("%d", &eRetorno.nacionalidad);
	printf("Ingrese tipo IPHONE 1 - MAC 2 - IPAD 3 - ACCCESORIOS 4");
	scanf("%d", &eRetorno.tipo);
	printf("Ingrese precio: ");
	scanf("%f", &eRetorno.precio);
	return eRetorno;
}

void cargarProductos(eProducto unProducto[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		if(unProducto[i].estado == LIBRE)
		{
			unProducto[i]=ingresoDeUnSoloProducto();
			unProducto[i].idproducto=i+1;
			unProducto[i].estado=OCUPADO;
			break;
		}
	}
}

void inicializarArray(eProducto unProducto[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		unProducto[i].estado=LIBRE;
	}
}

void listarTodosLosProductos(eProducto unProducto[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		if(unProducto[i].estado==OCUPADO)
		{
			printf("id: %d \t\t descripcion: %s \t\t nacionalidad: %d\t\t tipo: %d \t\t precio: %.2f\n", unProducto[i].idproducto, unProducto[i].descripcion, unProducto[i].nacionalidad, unProducto[i].tipo, unProducto[i].precio);
		}
	}
}

void borrarProducto(eProducto unProducto[], int tam)
{
	int numero;

	listarTodosLosProductos(unProducto, tam);
	printf("Indique el id a borrar: ");
	scanf("%d", &numero);
	for(int i=0;i<tam;i++)
	{
		if(unProducto[i].idproducto==numero)
		{
			unProducto[i].estado=LIBRE;
		}
	}
}

void modificarProducto(eProducto unProducto[], int tam)
{
	int numero;
	int numModificar;
	int nuevoNum;
	float nuevoNumero;

	listarTodosLosProductos(unProducto, tam);
	printf("Indique el id a modificar: ");
	scanf("%d", &numero);
	printf("Modificar 1 para precio y 2 para tipo: ");
	scanf("%d", &numModificar);
	for(int i=0;i<tam;i++)
	{
		if(unProducto[i].idproducto==numero)
		{
			switch(numModificar)
			{
			case 1:
				printf("Ingrese nuevo numero: ");
				scanf("%f", &nuevoNumero);
				unProducto[i].precio=nuevoNumero;
				break;
			case 2:
				printf("Ingrese nuevo numero: ");
				scanf("%d", &nuevoNum);
				unProducto[i].tipo=nuevoNum;
				break;
			}
		}
	}
}

void listarPorPrecio(eProducto unProducto[], int tam)
{
	int i;
	int j;
	float buffer;
	int bufferProducto;
	char bufferDes[50];
	int bufferNac;
	int bufferTipo;
	for(i = 0; i < tam-1; i++)
	{
		for(j = i+1; j < tam; j++)
		{
			if(unProducto[i].precio>unProducto[j].precio)
			{
				buffer=unProducto[i].precio;
				unProducto[i].precio=unProducto[j].precio;
				unProducto[j].precio=buffer;
				bufferProducto=unProducto[i].idproducto;
				unProducto[i].idproducto=unProducto[j].idproducto;
				unProducto[j].idproducto=bufferProducto;
				strcpy(bufferDes, unProducto[i].descripcion);
				strcpy(unProducto[i].descripcion, unProducto[j].descripcion);
				strcpy(unProducto[j].descripcion, bufferDes);
				bufferNac=unProducto[i].nacionalidad;
				unProducto[i].nacionalidad=unProducto[j].nacionalidad;
				unProducto[j].nacionalidad=bufferNac;
				bufferTipo=unProducto[i].tipo;
				unProducto[i].tipo=unProducto[j].tipo;
				unProducto[j].tipo=bufferTipo;
			}
		}
	}
}

void listarPorDescripcion(eProducto unProducto[], int tam)
{
	int i;
	int j;
	float buffer;
	int bufferProducto;
	char bufferDes[50];
	int bufferNac;
	int bufferTipo;
	for(i = 0; i < tam-1; i++)
	{
		for(j = i+1; j < tam; j++)
		{
			if(strcmp(unProducto[i].descripcion,unProducto[j].descripcion)==1)
			{
				buffer=unProducto[i].precio;
				unProducto[i].precio=unProducto[j].precio;
				unProducto[j].precio=buffer;
				bufferProducto=unProducto[i].idproducto;
				unProducto[i].idproducto=unProducto[j].idproducto;
				unProducto[j].idproducto=bufferProducto;
				strcpy(bufferDes, unProducto[i].descripcion);
				strcpy(unProducto[i].descripcion, unProducto[j].descripcion);
				strcpy(unProducto[j].descripcion, bufferDes);
				bufferNac=unProducto[i].nacionalidad;
				unProducto[i].nacionalidad=unProducto[j].nacionalidad;
				unProducto[j].nacionalidad=bufferNac;
				bufferTipo=unProducto[i].tipo;
				unProducto[i].tipo=unProducto[j].tipo;
				unProducto[j].tipo=bufferTipo;
			}
		}
	}
}
