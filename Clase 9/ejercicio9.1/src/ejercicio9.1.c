/*
 ============================================================================
Cubilla Damian
Ejercicio 9.1 :
Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
- idProducto (numerico)
-descripcion (alfanumérico)
- nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
- tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
- precio (numérico decimal)
Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
1.ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
2.BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
3.MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
4.LISTADO Productos.
5.LISTADO ordenado por precio.
6.LISTADO ordenado por descripción.
7.El/los  productos más caros.
8.Los productos que cuestan 700
9.Precio promedio por tipo de producto.
10.De los Iphone el más barato
11.Los productos "MADE IN CHINA"
12.Las MAC que cuestan más de 700 USD
13.El/Los Accesorios más caros

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "producto.h"


int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int cantidadProductos=3;
	eProducto arrayProductos[TAM];
	producto_inicializarPorductos(arrayProductos, TAM);
	producto_harcodeo(arrayProductos, TAM);

	do
	{
		pedirEntero(&opcion, "-------------------------------------\n"
				"1.ALTA Producto\n"
				"2.BAJA Producto\n"
				"3.MODIFICACIÓN Producto\n"
				"4.LISTADO Productos\n"
				"5.LISTADO ordenado por precio\n"
				"6.LISTADO ordenado por descripción\n"
				"7.El/Los productos mas caros\n"
				"8.Los productos que cuestan 700\n"
				"9.Precio promedio por tipo de producto\n"
				"10.De los Iphone el más barato\n"
				"11.Los productos MADE IN CHINA\n"
				"12.Las MAC que cuestan más de 700 USD\n"
				"13.El/Los Accesorios más caros\n"
				"14.---->Salir\n"
				"-------------------------------------\n"
				"Ingrese opcion: ",
				"-------------------------------------"
				"1.ALTA Producto\n"
				"2.BAJA Producto\n"
				"3.MODIFICACIÓN Producto\n"
				"4.LISTADO Productos\n"
				"5.LISTADO ordenado por precio\n"
				"6.LISTADO ordenado por descripción\n"
				"7.El/Los productos mas caros\n"
				"8.Los productos que cuestan 700\n"
				"9.Precio promedio por tipo de producto\n"
				"10.De los Iphone el más barato\n"
				"11.Los productos MADE IN CHINA\n"
				"12.Las MAC que cuestan más de 700 USD\n"
				"13.El/Los Accesorios más caros\n"
				"14.---->Salir\n"
				"-------------------------------------\n"
				"Opcion invalidad, reingrese: ", 1, 14);
		switch(opcion)
		{
		case 1:
			if(!producto_agregarProducto(arrayProductos, TAM))
			{
				cantidadProductos++;
			}
			system("pause");
			break;
		case 2:
			producto_mostrarTodosLosProducto(arrayProductos, TAM);
			if(!producto_borrarUnProducto(arrayProductos, TAM))
			{
				cantidadProductos--;
			}
			system("pause");
			break;
		case 3:
			producto_mostrarTodosLosProducto(arrayProductos, TAM);
			producto_ModificarUnProducto(arrayProductos, TAM);
			system("pause");
			break;
		case 4:
			if(cantidadProductos>0)
			{
				producto_mostrarTodosLosProducto(arrayProductos, TAM);
			}
			else
			{
				printf("No se ingreso ningun producto!\n");
			}
			system("pause");
			break;
		case 5:
			if(cantidadProductos>0)
			{
				producto_ordenarPorPrecio(arrayProductos, TAM);
			}
			else
			{
				printf("No se ingreso ningun producto!\n");
			}
			system("pause");
			break;
		case 6:
			if(cantidadProductos>0)
			{
				producto_ordenarPorDescripcion(arrayProductos, TAM);
			}
			else
			{
				printf("No se ingreso ningun producto!\n");
			}
			system("pause");
			break;
		case  7:
			if(cantidadProductos>0)
			{
				producto_MostrarMasCaro(arrayProductos, TAM);
			}
			else
			{
				printf("No se ingreso ningun producto!\n");
			}
			system("pause");
			break;
		case 8:
			if(cantidadProductos>0)
			{
				producto_CuestanSetecientos(arrayProductos, TAM);
			}
			else
			{
				printf("No se ingreso ningun producto!\n");
			}
			system("pause");
			break;
		case 9:
			break;
		case 10:
			if(cantidadProductos>0)
			{
				producto_IphoneMasBarato(arrayProductos, TAM);
			}
			else
			{
				printf("No se ingreso ninugun producto!\n");
			}
			system("pause");
			break;
		case 11:
			if(cantidadProductos>0)
			{
				producto_MadeInChina(arrayProductos, TAM);
			}
			else
			{
				printf("No se ingreso ninugun producto!\n");
			}
			system("pause");
			break;
		case 12:
			if(cantidadProductos>0)
			{
				producto_MacMasCostoso(arrayProductos, TAM);
			}
			else
			{
				printf("No se ingreso ninugun producto!\n");
			}
			system("pause");
			break;
		case 13:
			if(cantidadProductos>0)
			{
				producto_AccesoriosMasCaros(arrayProductos, TAM);
			}
			else
			{
				printf("No se ingreso ninugun producto!\n");
			}
			system("pause");
			break;
		}

	}while(opcion!=14);

	return EXIT_SUCCESS;
}

