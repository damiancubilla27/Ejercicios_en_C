
#ifndef PRODUCTO_H_
#define PRODUCTO_H_
//nacionalidad
#define EEUU 0
#define CHINA 1
#define OTRO 2
//tipo
#define IPHONE 0
#define MAC 1
#define IPAD 2
#define ACCESORIOS 3
//tamaño del array
#define TAM 5
//estado
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int idproducto;
	char descripcion[51];
	int nacionalidad;
	int tipo;
	float precio;
	int estado;
}eProducto;

void producto_inicializarPorductos(eProducto productos[], int tam);
void producto_mostrarUnProducto(eProducto producto);
void producto_mostrarTodosLosProducto(eProducto productos[], int tam);
int producto_buscarEspacioLibre(eProducto productos[], int tam);
eProducto producto_cargarUnProducto(void);
int producto_agregarProducto(eProducto productos[], int tam);
void producto_harcodeo(eProducto productos[],int tam);
int producto_verificarConfirmacion(char* mensaje);
// punto 2
int producto_buscarPorId(eProducto productos[], int tam, int id);
int producto_borrarUnProducto(eProducto productos[], int tam);
//punto 3
int producto_ModificarUnProducto(eProducto productos[], int tam);
//punto 5
void producto_ordenarPorPrecio(eProducto productos[], int tam);
//punto 6
void producto_ordenarPorDescripcion(eProducto productos[], int tam);
//punto 7
float producto_buscarProductoMasCaro(eProducto productos[], int tam);
void producto_MostrarMasCaro(eProducto productos[], int tam);
//punto 8
void producto_CuestanSetecientos(eProducto productos[], int tam);
//punto 10
int producto_BuscarIphoneBarato(eProducto productos[], int tam);
void producto_IphoneMasBarato(eProducto productos[], int tam);
//punto 11
void producto_MadeInChina(eProducto productos[], int tam);
//punto 12
void producto_MacMasCostoso(eProducto productos[], int tam);
//punto 13
void producto_AccesoriosMasCaros(eProducto productos[], int tam);
#endif /* PRODUCTO_H_ */
