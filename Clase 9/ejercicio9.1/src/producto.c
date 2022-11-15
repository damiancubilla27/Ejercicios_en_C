
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "producto.h"


void producto_inicializarPorductos(eProducto productos[], int tam)
{
	for(int i=0; i<tam;i++)
	{
		productos[i].estado=LIBRE;
	}
}


void producto_mostrarUnProducto(eProducto producto)
{
	printf("%-5d %-52s %-20d %-20d %-20.2f\n", producto.idproducto, producto.descripcion, producto.nacionalidad, producto.tipo, producto.precio);
}


void producto_mostrarTodosLosProducto(eProducto productos[], int tam)
{
	printf("%-5s %-52s %-20s %-20s %-20s\n", "id", "descripcion", "nacionalidad", "tipo", "precio");
	for(int i=0; i<tam;i++)
	{
		if(productos[i].estado==OCUPADO)
		{
			producto_mostrarUnProducto(productos[i]);
		}
	}
}

int producto_buscarEspacioLibre(eProducto productos[], int tam)
{
	int retorno = -1;
	for(int i=0;i<tam;i++)
	{
		if(productos[i].estado==LIBRE)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

eProducto producto_cargarUnProducto()
{
	eProducto auxProducto;
	pedirCadena(auxProducto.descripcion, "Ingrese la descripcion: ", "Error, Reingrese: \n", 51);
	pedirEntero(&auxProducto.nacionalidad, "Ingrese nacionalidad (EEUU = 0 , CHINA = 1, OTRO = 2): ", "Error, Reingrese: \n", 0, 2);
	pedirEntero(&auxProducto.tipo, "Ingrese tipo (IPHONE = 0, MAC = 1, IPAD = 2, ACCESORIOS = 3): ", "Error, Reingrese: \n", 0, 3);
	pedirFlotante(&auxProducto.precio, "Ingrese precio: ", "Error, Reingrese: \n", 1, 1000);
	return auxProducto;
}

int producto_agregarProducto(eProducto productos[], int tam)
{
	int retorno = -1;
	int index = producto_buscarEspacioLibre(productos, tam);

	if(index != -1)
	{
		if(producto_verificarConfirmacion("Ingrese S para agregar producto: ")==0)
		{
			productos[index] = producto_cargarUnProducto();
			productos[index].estado=OCUPADO;
			productos[index].idproducto=index+1;
			printf("El producto se agrego correctamente!\n");
			retorno=0;
		}
		else
		{
			printf("Se cancelo el agregar un producto\n");
		}
	}


	if(index==-1)
	{
		printf("Ya no tengo mas lugar maquina!!\n");
	}
	return retorno;
}

void producto_harcodeo(eProducto productos[],int tam)
{
	char descripcion[][51]={"Iphone 12","Mac 5","Accesorio"};
	int nacionalidad[]={EEUU,CHINA,OTRO};
	int tipo[]={IPHONE,MAC,ACCESORIOS};
	float precios[]={111, 52.3, 20.22222};

	for(int i=0;i<tam-2;i++)
	{
		strcpy(productos[i].descripcion,descripcion[i]);
		productos[i].nacionalidad=nacionalidad[i];
		productos[i].tipo=tipo[i];
		productos[i].precio=precios[i];
		productos[i].idproducto=i+1;
		productos[i].estado=OCUPADO;
	}
}

int producto_borrarUnProducto(eProducto productos[], int tam)
{
	int retorno=-1;
	int numero;
	int index;
	pedirEntero(&numero, "Ingrese el id a eliminar: ", "Error, Reingrese: ", 0, 5);
	index = producto_buscarPorId(productos, tam, numero);

	if(index!=-1)
	{
		if(producto_verificarConfirmacion("Ingrese S para confirmar la eliminacion del producto: ")==0)
		{
			productos[index].estado = LIBRE;
			printf("El producto %s se dio de baja correctamente\n", productos[index].descripcion);
			retorno=0;
		}
		else
		{
			printf("Se cancelo la baja del producto!\n");
		}
	}
	else
	{
		printf("Producto no encontrado..\n");
	}
	return retorno;
}

int producto_buscarPorId(eProducto productos[], int tam, int id)
{
	int index=-1;
	for(int i=0; i<tam;i++)
	{
		if(productos[i].estado==OCUPADO && productos[i].idproducto==id)
		{
			index=i;
			break;
		}
	}
	return index;
}

int producto_verificarConfirmacion(char* mensaje)
{
	int retorno=-1;
	char respuesta;
	pedirCaracter(&respuesta, mensaje);
	if(respuesta=='s' || respuesta=='S')
	{
		retorno=0;
	}
	return retorno;
}

int producto_ModificarUnProducto(eProducto productos[], int tam)
{
	int retorno=-1;
	int idIngresado;
	int index;
	int opcion;
	eProducto auxProducto;

	pedirEntero(&idIngresado, "Ingrese el id del producto a modificar: ", "Error, Reingrese: ", 1, 5);
	index = producto_buscarPorId(productos, tam, idIngresado);
	if(index != -1)
	{
		do
		{
			pedirEntero(&opcion, "1. Modificar el precio\n2.Modificar el tipo\n3. Volver al menu principal\nIngrese opcion: ", "Error, Reingrese: ", 1, 3);
			switch(opcion)
			{
			case 1:
				pedirFlotante(&auxProducto.precio, "Ingrese el nuevo precio: ", "Error, reingrese: ", 1, 1000);
				productos[index].precio=auxProducto.precio;
				printf("El producto %s modificado correctamente!!\n", productos[index].descripcion);
				retorno=0;
				system("pause");
				break;
			case 2:
				pedirEntero(&auxProducto.tipo, "Ingrese el nuevo tipo: ", "Error, Reingrese: ", 0, 3);
				productos[index].tipo=auxProducto.tipo;
				printf("El producto %s modificado correctamente!!\n", productos[index].descripcion);
				retorno=0;
				system("pause");
				break;
			}

		}while(opcion != 3);
	}
	else
	{
		printf("Error, producto no encontrado..");
	}

	return retorno;
}

void producto_ordenarPorPrecio(eProducto productos[], int tam)
{
	eProducto auxProduc;
	for(int i=0;i<tam-1;i++)
	{
		for(int j=i+1;j<tam;j++)
		{
			if(productos[i].estado==OCUPADO && productos[j].estado==OCUPADO && productos[i].precio>productos[j].precio)
			{
				auxProduc = productos[i];
				productos[i] = productos[j];
				productos[j] = auxProduc;
			}
		}
	}
}

void producto_ordenarPorDescripcion(eProducto productos[], int tam)
{
	eProducto auxProduc;
	for(int i=0;i<tam-1;i++)
	{
		for(int j=i+1;j<tam;j++)
		{
			if(productos[i].estado==OCUPADO && productos[j].estado==OCUPADO && strcmp(productos[i].descripcion, productos[j].descripcion)==1)
			{
				auxProduc = productos[i];
				productos[i] = productos[j];
				productos[j] = auxProduc;
			}
		}
	}
}

float producto_buscarProductoMasCaro(eProducto productos[], int tam)
{
	float precioMayor;
	int flag=0;

	for(int i=0;i<tam;i++)
	{
		if(productos[i].estado==OCUPADO)
		{
			if(flag==0 || productos[i].precio>precioMayor)
			{
				precioMayor=productos[i].precio;
				flag=1;
			}
		}
	}
	return precioMayor;
}

void producto_MostrarMasCaro(eProducto productos[], int tam)
{
	float precioMayor = producto_buscarProductoMasCaro(productos, tam);
	printf("El/los  productos más caros:\n");
	printf("%-5s %-52s %-20s %-20s %-20s\n", "id", "descripcion", "nacionalidad", "tipo", "precio");
	for(int i=0;i<tam;i++)
	{
		if(productos[i].estado==OCUPADO && productos[i].precio==precioMayor)
		{
			producto_mostrarUnProducto(productos[i]);
		}
	}
}

void producto_CuestanSetecientos(eProducto productos[], int tam)
{
	int contador=0;
	printf("El/los productos que cuestan 700:\n");
	for(int i=0;i<tam;i++)
	{
		if(productos[i].estado==OCUPADO && productos[i].precio==700)
		{
			printf("El producto que vale 700.00 es: %s\n", productos[i].descripcion);
			contador++;
		}
	}

	if(contador==0)
	{
		printf("No se encontro ningun producto que cueste 700$\n");
	}
}

int producto_BuscarIphoneBarato(eProducto productos[], int tam)
{
	float precioBarato;
	int flag=0;
	int retorno=-1;
	for(int i=0;i<tam;i++)
	{
		if(productos[i].estado==OCUPADO && productos[i].tipo==0)
		{
			if(flag==0 || productos[i].precio<precioBarato)
			{
				precioBarato=productos[i].precio;
				retorno=i;
			}
		}
	}
	return retorno;
}

void producto_IphoneMasBarato(eProducto productos[], int tam)
{
	int precioBarato=producto_BuscarIphoneBarato(productos, tam);
	printf("El Iphone mas barato es:\n");
	if(precioBarato!=-1)
	{
		printf("%-5s %-52s %-20s %-20s %-20s\n", "id", "descripcion", "nacionalidad", "tipo", "precio");
		producto_mostrarUnProducto(productos[precioBarato]);
	}
	else
	{
		printf("No se encontro ningun iphone barato\n\n");
	}
}

void producto_MadeInChina(eProducto productos[], int tam)
{
	printf("Los productos 'Made in China' son: \n");
	printf("%-5s %-52s %-20s %-20s %-20s\n", "id", "descripcion", "nacionalidad", "tipo", "precio");
	for(int i=0;i<tam;i++)
	{
		if(productos[i].estado==OCUPADO && productos[i].nacionalidad==1)
		{
			producto_mostrarUnProducto(productos[i]);
		}
	}
}

void producto_MacMasCostoso(eProducto productos[], int tam)
{
	printf("Los productos Mac de mas 700$ son: \n");
	printf("%-5s %-52s %-20s %-20s %-20s\n", "id", "descripcion", "nacionalidad", "tipo", "precio");
	for(int i=0;i<tam;i++)
	{
		if(productos[i].estado==OCUPADO && productos[i].tipo==MAC && productos[i].precio>700)
		{
			producto_mostrarUnProducto(productos[i]);
		}
	}
}

void producto_AccesoriosMasCaros(eProducto productos[], int tam)
{
	printf("El/Los accesorios mas caros son: \n");
	printf("%-5s %-52s %-20s %-20s %-20s\n", "id", "descripcion", "nacionalidad", "tipo", "precio");
	for(int i=0;i<tam;i++)
	{
		if(productos[i].estado==OCUPADO && productos[i].tipo==ACCESORIOS)
		{
			producto_mostrarUnProducto(productos[i]);
		}
	}
}
