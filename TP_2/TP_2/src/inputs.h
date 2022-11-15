#ifndef INPUTS_H_
#define INPUTS_H_
/**
 * @fn int utn_getEnteroCorto(short*, char*, char*, int, int)
 * @brief Funcion que nos permite ingresar un numero entero corto, con mensaje a ingresar y mensaje de error para reingresar. Esta funcion tiene limites de minimo y maximo numero.
 *
 * @param entero Puntero a una variable de entero corto.
 * @param mensaje Mensaje que para ingresar dato.
 * @param mensajeError Mensaje de error al ingresar un dato incorrecto.
 * @param minimo Limite minimo para el numero.
 * @param maximo Limite maximo para el numero.
 * @return Retorna 0 en caso de que el dato fue ingresado correctamente o retorna -1 en caso de que fue mal ingresado el dato.
 */
int utn_getEnteroCorto(short* entero, char* mensaje, char* mensajeError, int minimo, int maximo);

/**
 * @fn int utn_getNumeroEntero(int*, char*, char*, int, int)
 * @brief Funcion que nos permite ingresar un numero entero, con mensaje a ingresar y mensaje de error para reingresar. Esta funcion tiene limites de minimo y maximo numero.
 *
 * @param entero Puntero a una variable de entero.
 * @param mensaje Mensaje que para ingresar dato.
 * @param mensajeError Mensaje de error al ingresar un dato incorrecto.
 * @param minimo Limite minimo para el numero.
 * @param maximo Limite maximo para el numero.
 * @return Retorna 0 en caso de que el dato fue ingresado correctamente o retorna -1 en caso de que fue mal ingresado el dato.
 */
int utn_getNumeroEntero(int* entero, char* mensaje, char* mensajeError, int minimo, int maximo);

/**
 * @fn int utn_getArrayCadena(char*, char*, char*, int)
 * @brief Funcion que nos permite ingresar un array de caracteres, con mensaje a ingresar y mensaje de error para reingresar. Esta funcion tiene limite de maximo caracteres.
 *
 * @param cadena Puntero a un array de caracteres.
 * @param mensaje Mensaje que para ingresar dato.
 * @param mensajeError Mensaje de error al ingresar un dato incorrecto.
 * @param max Limite maximo para la cadena de caracteres.
 * @return Retorna 0 en caso de que el dato fue ingresado correctamente o retorna -1 en caso de que fue mal ingresado el dato.
 */
int utn_getArrayCadena(char* cadena, char* mensaje, char* mensajeError, int max);

/**
 * @fn int utn_getNumeroFlotante(float*, char*, char*, float, float)
 * @brief Funcion que nos permite ingresar un numero flotante, con mensaje a ingresar y mensaje de error para reingresar. Esta funcion tiene limites de minimo y maximo de numero flotante.
 *
 * @param flotante Puntero a una variable de numero flotante.
 * @param mensaje Mensaje que para ingresar dato.
 * @param mensajeError Mensaje de error al ingresar un dato incorrecto.
 * @param min Limite minimo para el numero.
 * @param max Limite maximo para el numero.
 * @return Retorna 0 en caso de que el dato fue ingresado correctamente o retorna -1 en caso de que fue mal ingresado el dato.
 */
int utn_getNumeroFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);

/**
 * @fn int utn_getCaracter(char*, char*, char, char, char, char)
 * @brief Funcion que nos permite ingresar un caracter, con mensaje a ingresar y mensaje de error para reingresar. Esta funcion tiene limite de minimo y maximo (tanto en minuscula como en mayuscula) caracter.
 *
 * @param caracter Puntero a una variable de un solo caracter.
 * @param mensaje Mensaje que para ingresar dato.
 * @param min  Limite minimo en minuscula para el caracter.
 * @param max Limite maximo en minuscula para el caracter.
 * @param minMay Limite minimo en mayuscula para el caracter.
 * @param maxMay Limite maximo en mayuscula para el caracter.
 * @return Retorna 0 en caso de que el dato fue ingresado correctamente o retorna -1 en caso de que fue mal ingresado el dato.
 */
int utn_getCaracter(char* caracter, char* mensaje, char min, char max, char minMay, char maxMay);


#endif /* INPUTS_H_ */
