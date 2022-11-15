/*
 ============================================================================
Cubilla Damian
Ejercicio 17-1:
Realizar una función que retorne un puntero a eProducto.
Dentro de esta función deberá crear un producto hardcodeado, un puntero y
se apuntará ese puntero al producto. Mostrar el producto cargado 5 veces desde
el main. Observar el comportamiento del programa.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct{
	int id;
	char nombre[20];
	float precio;
}eProducto;

eProducto* crearProducto(void);//Constructor por defecto
eProducto* crearProductoConParametros(int numero, char* nombreProducto, float salario);//Constructor parametrizado
int mostrarUnProducto(eProducto* produc, int tam);

int main(void) {
	setbuf(stdout, NULL);
	eProducto* otroProduc;
	otroProduc = crearProductoConParametros(15, "Damian", 25000);

	if(mostrarUnProducto(otroProduc, TAM)==-1)
	{
		printf("Salio Mal!\n");
	}

	return EXIT_SUCCESS;
}

eProducto* crearProducto(void)//Constructor
{
	eProducto* pProducto;
	pProducto = (eProducto*)malloc(sizeof(eProducto));//Construye espacio en memoria
	if(pProducto!=NULL)
	{
		pProducto->id=0;//Asigna o inicializa valores
		strcpy(pProducto->nombre,"\0");
		pProducto->precio=0;
	}

	return pProducto;
}

eProducto* crearProductoConParametros(int numero, char* nombreProducto, float salario)
{
	eProducto* pProducto;
	pProducto = crearProducto();
	if(pProducto!=NULL)
	{
		pProducto->id=numero;
		strcpy(pProducto->nombre,nombreProducto);
		pProducto->precio=salario;
	}
	return pProducto;
}

int mostrarUnProducto(eProducto* produc, int tam)
{
	int retorno=-1;
	if(produc!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			printf("%d--%s--%.2f\n",produc->id,produc->nombre,produc->precio);
		}
		retorno=0;
	}

	return retorno;
}




