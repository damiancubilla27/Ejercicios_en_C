#ifndef JUGADOR_H_
#define JUGADOR_H_

#define TAM 3000
#define LIBRE 1
#define OCUPADO 0

typedef struct
{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;
}eConfederacion;

typedef struct
{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;

//Punto 1

/**
 * @fn void jugador_inicializarJugadores(eJugador[], int)
 * @brief Esta funcion nos permite poner en libre cada uno de la las posiciones del array jugador.
 *
 * @param listaJugadores Array de la entidad jugador.
 * @param tam Tamañano del array jugador.
 */
void jugador_inicializarJugadores(eJugador listaJugadores[], int tam);

/**
 * @fn int jugador_buscarEspacioLibre(eJugador[], int)
 * @brief La funcion permite buscar un espacio libre en el vector jugador, en caso que la encuentra nos devuelve el inidice y en caso de que no un menos uno.
 *
 * @param listaJugadores Vector de la entidad jugador.
 * @param tam Size del vector jugador.
 * @return En caso de que encuentre un espacio libre retorna el indice y en caso de que no devuelve -1.
 */
int jugador_buscarEspacioLibre(eJugador listaJugadores[], int tam);

/**
 * @fn eJugador jugador_cargarUnJugador(void)
 * @brief Funcion que se encarga de crear un jugador para poder cargar al sistema.
 *
 * @return Retorna el jugador cargado.
 */
eJugador jugador_cargarUnJugador(void);

/**
 * @fn void jugador_agregarJugador(eJugador[], int)
 * @brief Evalua y pide confirmacion para poder cargar el nuevo jugador, en caso de que el vector jugador no tenga mas espacio notifica que no se puede agregar mas jugadores.
 *
 * @param listajugadores Vector jugador.
 * @param tam Tamaño del vector jugador.
 */
void jugador_agregarJugador(eJugador listajugadores[], int tam);

// Punto 2

/**
 * @fn void jugador_mostrarTodosLosJugadores(eJugador[], int, eConfederacion[], int)
 * @brief Funcion que se encarga de mostrar los jugadores cargados al sistema. Con sus respectivos id, nombre, posicion, n° de camiseta, sueldo, confederacion y años de contrato.
 *
 * @param listajugadores Array de jugador.
 * @param tam Tamaño de el array jugador.
 * @param listaConfe Array de confederacion.
 * @param tamano Tamaño de el array confederacion.
 */
void jugador_mostrarTodosLosJugadores(eJugador listajugadores[], int tam, eConfederacion listaConfe[], int tamano);

/**
 * @fn void jugador_listarConfederacion(eJugador[], int, eConfederacion[], int)
 * @brief Esta funcion se integra a la funcion jugador_mostrarTodosLosJugadores para mostrar el nombre de la confederacion.
 *
 * @param listajugadores Array de jugador.
 * @param index Indice de la condeferacion donde se pide el nombre.
 * @param listaConfe Array de confederacion.
 * @param tamano tamaño de el array confederacion.
 */
void jugador_listarConfederacion(eJugador listajugadores[], int index, eConfederacion listaConfe[],int tamano);

/**
 * @fn int jugador_bajaDeJugador(eJugador[], int, eConfederacion[], int)
 * @brief Funcion que pide id del juagador a dar de baja del sistema. Luego pide confirmacion para poder eliminar del sistema.
 *
 * @param listajugadores Array de jugador.
 * @param tam Tamaño de el array jugador.
 * @param listaConfe Array de confederacion.
 * @param tamano tamaño de el array confederacion.
 * @return Retorna 0 en caso de que el dato fue ingresado correctamente o retorna -1 en caso de que fue mal ingresado el dato.
 */
int jugador_bajaDeJugador(eJugador listajugadores[], int tam, eConfederacion listaConfe[],int tamano);

/**
 * @fn int jugador_buscarPorId(eJugador[], int, int)
 * @brief Permite buscar el id del jugador a querer eliminar.
 *
 * @param listajugadores Vector de jugador.
 * @param tam Tamaño de la vector jugador.
 * @param id Parametro id que ingresa el usuario.
 * @return Retorna el indice del id encontrado en caso de que el dato fue ingresado correctamente o retorna -1 en caso de que fue mal ingresado el dato o no fue encontrado.
 */
int jugador_buscarPorId(eJugador listajugadores[], int tam, int id);

// Punto 3
/**
 * @fn int jugador_modificarJugador(eJugador[], int, eConfederacion[], int)
 * @brief Permite modificar cada de uno de los datos que tienen los jugadores ingresados.
 *
 * @param listajugadores Vector de jugadores.
 * @param tam Tamaño del vector jugador.
 * @param listaConfe Vector de confederacion.
 * @param tamano Tamaño del vector confederacion.
 * @return Retorna 0 en caso de que el jugador fue modificado correctamente o -1 en caso de que el id no fue encontrado.
 */
int jugador_modificarJugador(eJugador listajugadores[], int tam, eConfederacion listaConfe[],int tamano);

// Punto 4
/**
 * @fn int jugador_listarImformes(eJugador[], int, eConfederacion[], int)
 * @brief Menu de opciones donde podra elegir listar cada uno de los puntos de la opcion cuatro (informes).
 *
 * @param listajugadores Array de jugador.
 * @param tam Tamaño del array jugador.
 * @param listaConfe Array de confederacion.
 * @param tamano Tamaño del array confederacion.
 * @return Retorna 0 en caso de que funcione bien y -1 en caso de que no funcione.
 */
int jugador_listarImformes(eJugador listajugadores[], int tam, eConfederacion listaConfe[], int tamano);

//--------- punto 4.1
/**
 * @fn int jugador_ordenarAlfabeticamente(eJugador[], int, eConfederacion[], int)
 * @brief Permite ordenar y listar alfabeticamente las confederaciones de los jugadores, en caso de que tenga la misma confederacion se ordenara por los nombres de los jugadores.
 *
 * @param listajugadores Vector de jugador.
 * @param tam Tamaño del vector jugador.
 * @param listaConfe Vector confederacion.
 * @param tamano Tamaño del vector confederacion.
 * @return Retorna 0 en caso de que funcione bien y -1 en caso de que no funcione.
 */
int jugador_ordenarAlfabeticamente(eJugador listajugadores[], int tam, eConfederacion listaConfe[], int tamano);

/**
 * @fn void jugador_nombreConfederacion(eConfederacion[], int, int, char*)
 * @brief Busca el nombre de la confederacion y copia su nombre para que en otra funcion pueda ordenar alfabeticamente.
 *
 * @param listaConfe Vector confederacion.
 * @param tamConfe Tamaño del vector confederacion.
 * @param indice Id de confederacion donde busca el nombre.
 * @param nombre Pasa por puntero la copia del nombre de confederacion que se encuentra en esa posicion.
 */
void jugador_nombreConfederacion(eConfederacion listaConfe[], int tamConfe, int indice, char* nombre);

//--------- punto 4.2
/**
 * @fn int jugador_confirmarJugadorPorConfederacion(eJugador[], int, int)
 * @brief Funcion que sirve para saber si se ingreso un jugador de esa confederacion.
 *
 * @param listajugadores Array de jugador.
 * @param tam Tamaño de el array jugador.
 * @param index indice de la confederacion.
 * @return Retorna 0 en caso de que se encontro jugador o retorna -1 en caso de que no.
 */
int jugador_confirmarJugadorPorConfederacion(eJugador listajugadores[], int tam, int index);

/**
 * @fn void jugador_listarJugadorPorConfederacion(eJugador[], int, int, eConfederacion[], int)
 * @brief Lista el jugador de que se encuentra en esa confederacion.
 *
 * @param listajugadores Array de jugador.
 * @param tam Tamaño de el array jugador.
 * @param index indice de la confederacion.
 * @param listaConfe Array de confederacion.
 * @param tamano Tamaño de el array de confederacion.
 */
void jugador_listarJugadorPorConfederacion(eJugador listajugadores[], int tam, int index, eConfederacion listaConfe[], int tamano);

/**
 * @fn void jugador_imprimirJugadorConfederacion(eJugador[], int, eConfederacion[], int)
 * @brief Imprime cada una de las confederaciones y si contienen jugadores los imprime, en caso que no imprime un mensaje de jugador no ingresado en la confederacion.
 *
 * @param listajugadores Array de jugador.
 * @param tam Tamaño de el array jugador.
 * @param listaConfe Array de confederacion.
 * @param tamano Tamaño de el array confederacion.
 */
void jugador_imprimirJugadorConfederacion(eJugador listajugadores[], int tam, eConfederacion listaConfe[], int tamano);

/**
 * @fn void jugador_imprimirCarteleraConfe(char*)
 * @brief Imprime la cartelara de cada una de las confederaciones.
 *
 * @param confederacion Puntero con el nombre de la confederacion a la que va a imprimir.
 */
void jugador_imprimirCarteleraConfe(char* confederacion);

/**
 * @fn void jugador_imprimirSeparadorConfe(void)
 * @brief Esta funcion sirve simplemente para cerrar el cuadrito de cada una de las confederaciones.
 *
 */
void jugador_imprimirSeparadorConfe(void);
//--------- punto 4.3
/**
 * @fn void jugador_listarTotalYPromedio(eJugador[], int)
 * @brief Imprimer el total, el promedio y el en caso de pasar el promedio salarial.
 *
 * @param listajugadores Vector de jugador.
 * @param tam Tamaño de vector jugador.
 */
void jugador_listarTotalYPromedio(eJugador listajugadores[], int tam);

/**
 * @fn void juagador_TotalJugador(eJugador[], int, float*, int*)
 * @brief Pasa por puntero el total salarial y la cantidad de jugadores.
 *
 * @param listajugadores Array de jugador.
 * @param tam tamaño de array jugador.
 * @param total Puntero a variable que contabiliza el total salarial.
 * @param cantidad Puntero a variable que contibiliza la cantidad de jugadores ingresados.
 */
void juagador_TotalJugador(eJugador listajugadores[], int tam, float* total, int* cantidad);

/**
 * @fn float jugador_contarTotalSalario(float, int)
 * @brief Ingresan el total salarial y la cantidad de jugadores ingresados, realiza el calculo para que devuelva el promedio salarial.
 *
 * @param total Total de todos los salarios.
 * @param cantidad Cantidad de jugadores ingresados.
 * @return Retorna el promedio salarial de los jugadores ingresados.
 */
float jugador_contarTotalSalario(float total, int cantidad);

/**
 * @fn int jugador_superanPromedio(eJugador[], int, float)
 * @brief Analiza el promedio salarial y contabiliza cuantos jugadores pasan ese promedio.
 *
 * @param listajugadores Array de jugadores.
 * @param tam Tamaño de array jugador.
 * @param prom Promedio general salarial de todos los jugadores.
 * @return Devuelve el numero de jugadores que pasan el promedio salarial, en caso de que ningun jugador pase, se devolvera 0.
 */
int jugador_superanPromedio(eJugador listajugadores[], int tam, float prom);

//--------- punto 4.4
/**
 * @fn void jugador_imformarConfeMayorEnContratos(eJugador[], int)
 * @brief Se encarga de analizar que confederacion es que tiene mayor cantidad de años de contrato.
 *
 * @param listajugadores Vector de jugadores.
 * @param tam Tamaño de vector jugador.
 */
void jugador_imformarConfeMayorEnContratos(eJugador listajugadores[], int tam);

/**
 * @fn int jugador_ConfePorAnios(eJugador[], int, int)
 * @brief Acumula la cantidad de años por jugador y por confederacion.
 *
 * @param listajugadores Array de jugador.
 * @param tam Tamaño de array jugador.
 * @param index Id de confederacion a analizar.
 * @return Retorna 0 en caso de que ningun jugador fue ingresado en la confederacion o retorna la cantidad de años de contrato que tienen los jugadores de la confederacion.
 */
int jugador_ConfePorAnios(eJugador listajugadores[], int tam, int index);

/**
 *
 * @fn void jugador_imprimirConfeMayor(char*, int)
 * @brief Imprime la confederacion que tiene mayor cantidad de añios de contrato.
 *
 * @param confederacion Imprime la confederacion pasada por parametro.
 * @param anios Imprime los años de contrato que tiene la confederacion.
 */
void jugador_imprimirConfeMayor(char* confederacion, int anios);

//--------- punto 4.5
/**
 * @fn void jugador_imformarPorcentajeConfe(eJugador[], int)
 * @brief Imprime el porcentaje que tienen cada una de las confederaciones en el total de jugadores ingresados.
 *
 * @param listajugadores Vector de jugadores.
 * @param tam Tamaño de vector jugador.
 */
void jugador_imformarPorcentajeConfe(eJugador listajugadores[], int tam);

/**
 * @fn int jugador_totalJugadores(eJugador[], int)
 * @brief Contabiliza la cantidad de jugadores ingresados.
 *
 * @param listajugadores Array de jugador.
 * @param tam Tamaño de array jugador.
 * @return Retorna la cantidad de jugadores que fue ingresado en el sistema.
 */
int jugador_totalJugadores(eJugador listajugadores[], int tam);

/**
 * @fn int jugador_acumuladorPorConfe(eJugador[], int, int)
 * @brief Acumula la cantidad de jugadores por confederaciones y devuelve dicho numero.
 *
 * @param listajugadores Vector jugador.
 * @param tam Tamaño de vector jugador.
 * @param index indice de confederacion a buscar.
 * @return Retorna la cantidad de jugadores ingresados por confederacion.
 */
int jugador_acumuladorPorConfe(eJugador listajugadores[], int tam, int index);

/**
 * @fn float jugador_calcularPorcentaje(int, int)
 * @brief Encargado de contar el porcentaje que cuenta cada una de las confederaciones sobre el total de jugadores.
 *
 * @param numeConfe Numero de jugadores ingresados a la confederacion.
 * @param totalJuga Total de jugadores ingresados al sistema.
 * @return Devuelve el porcentaje de jugadores ingresados al sistema.
 */
float jugador_calcularPorcentaje(int numeConfe, int totalJuga);

//--------- punto 4.6
/**
 * @fn void jugador_informarRegionMasJugadores(eJugador[], int, eConfederacion[], int)
 * @brief Calcula e informa la region con mas jugadores en el sistema.
 *
 * @param listajugadores Array de jugador.
 * @param tam Tamaño de array jugador.
 * @param listaConfe Array de confederacion.
 * @param tamano Tamaño de array confederacion.
 */
void jugador_informarRegionMasJugadores(eJugador listajugadores[], int tam, eConfederacion listaConfe[], int tamano);

/**
 * @fn void jugador_calcularRegion(eJugador[], int, int, int*)
 * @brief Acumula la cantidad de jugadores ingresados por region y duelve dicho numero por puntero.
 *
 * @param listajugadores Vector de jugador.
 * @param tam Tamaño de vector jugador.
 * @param index id de la region a buscar.
 * @param numeroJugares Puntero que guarda la cantidad de jugadores.
 */
void jugador_calcularRegion(eJugador listajugadores[], int tam, int index, int* numeroJugares);

/**
 * @fn void jugador_mostrarRegionConMasJuga(eJugador[], int, eConfederacion[], int, int)
 * @brief Muestra los jugadores de la region con mas participacion en el sistema.
 *
 * @param listajugadores Array de jugador.
 * @param tam Tamaño de array jugador.
 * @param listaConfe Array de confederacion.
 * @param tamano Tamaño de array confederacion.
 * @param index id de la region con mas participaciones.
 */
void jugador_mostrarRegionConMasJuga(eJugador listajugadores[], int tam, eConfederacion listaConfe[], int tamano, int index);

//Punto 5
/**
 * @fn int jugador_verificarConfirmacion(char*)
 * @brief Verifica el caracter ingresado.
 *
 * @param mensaje Mensaje que pedira el dato.
 * @return Retorna 0 en caso de que funcione bien o -1 en caso de que funcione mal.
 */
int jugador_verificarConfirmacion(char* mensaje);

/**
 * @fn void jugador_verificarSalida(int*)
 * @brief Verifica que el usuario quiera salir de programa.
 *
 * @param numero Numero ingresado por el usuario.
 */
void jugador_verificarSalida(int* numero);

//-------------- Confederacion
/**
 * @fn void confederacion_inicializarConfederaciones(eConfederacion[], int)
 * @brief Esta funcion se encarga de inicializar cada uno de los indices de array confederacion.
 *
 * @param listaConfe Array confederacion.
 * @param tamano Tamaño de array confederacion.
 */
void confederacion_inicializarConfederaciones(eConfederacion listaConfe[], int tamano);

/**
 * @fn int confederacion_buscarLibreConfederacion(eConfederacion[], int)
 * @brief Busca espacio libre en la vector confederacion.
 *
 * @param listaConfe Vector confederacion.
 * @param tamano Tamaño de vetor confederacion.
 * @return Retorna el indice del lugar que se encuentra libre, en caso de estar lleno devuelve -1.
 */
int confederacion_buscarLibreConfederacion(eConfederacion listaConfe[], int tamano);

/**
 * @fn eConfederacion confederacion_crearUnaNuevaConfe(void)
 * @brief Crea una nueva confederacion para dar de alta al sistema.
 *
 * @return Retorna la nueva confederacion.
 */
eConfederacion confederacion_crearUnaNuevaConfe(void);

/**
 * @fn void confederacion_agregarConfe(eConfederacion[], int)
 * @brief Analiza y chequea que se quiera subir la nueva confederacion.
 *
 * @param listaConfe Array de confederacion.
 * @param tamano Tamaño de array confederacion.
 */
void confederacion_agregarConfe(eConfederacion listaConfe[], int tamano);

/**
 * @fn int confederacion_confirmacionDeConfe(char*)
 * @brief Se encarga de confirma o no si se puede subir esa nueva confederacion.
 *
 * @param mensaje Mensaje para poder dar de alta la nueva confederacion.
 * @return Retorna 0 en caso de que si pudo dar de alta correctamente o devuelve -1 en caso de que no.
 */
int confederacion_confirmacionDeConfe(char* mensaje);

/**
 * @fn void confederacion_mostrarTodosLasConfe(eConfederacion[], int)
 * @brief Imprime cada una de las confederaciones ingresadas.
 *
 * @param listaConfe Vector de confederacion.
 * @param tamano Tamaño de vector confederacion.
 */
void confederacion_mostrarTodosLasConfe(eConfederacion listaConfe[], int tamano);

/**
 * @fn int confederacion_bajaDeConfe(eConfederacion[], int)
 * @brief Analiza y verifica que se quiera dar de baja el jugador.
 *
 * @param listaConfe Array de confederacion.
 * @param tamano Tamaño de array confederacion.
 * @return En caso de que se pudo dar de baja devuelve 0, en caso de que no devuelve -1.
 */
int confederacion_bajaDeConfe(eConfederacion listaConfe[],int tamano);

/**
 * @fn int confederacion_buscarPorId(eConfederacion[], int, int)
 * @brief Buscar el id de la confederacion a dar de baja.
 *
 * @param listaConfe Vector de confederacion.
 * @param tamano Tamaño de vector confederacion.
 * @param id Id de la confederacion a dar de baja.
 * @return Devuelve el id en caso de que lo encontro o devuelve -1 en caso de que no.
 */
int confederacion_buscarPorId(eConfederacion listaConfe[],int tamano, int id);

/**
 * @fn int confederacion_modificarConfe(eConfederacion[], int)
 * @brief Permite modificar la confederacion, es decir, cambiar cada uno de los campos que se ingreso en la confederacion que indiquemos.
 *
 * @param listaConfe Vector de confederacion.
 * @param tamano Tamaño de vector confederacion.
 * @return Retorna 0 en caso de que se pudo modificar o retorna -1 en caso de que no.
 */
int confederacion_modificarConfe(eConfederacion listaConfe[],int tamano);

#endif /* JUGADOR_H_ */
