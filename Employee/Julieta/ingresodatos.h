#ifndef INGRESODATOS_H_INCLUDED
#define INGRESODATOS_H_INCLUDED

/**
 * \brief Solicita un número al usuario que el mismo ingresa como un strnig
 * \param mensaje Es el mensaje a ser mostrado
 * \param el valor minimo para ese flotante
  * \param el valor maximo para ese flotante
 * \return El número ingresado por el usuario tipo flotante natural
 *
 */


float IngresarEnteroFlotante(char [], int , int );

/**
 * \brief Valida strnig que posea solo numeros en un rago flotante
 * \param mensaje Es el mensaje a ser mostrado
 * \param el valor minimo para ese flotante
  * \param el valor maximo para ese flotante
 * \return El número ingresado por el usuario tipo flotante natural
 *
 */

float validarEnteroFlotante(char [], int , int , int );

/**
 * \brief Valida flotante entero ingresado este comprendido en un rango
  * \param el valor flotante
 * \param el valor minimo para ese flotante
  * \param el valor maximo para ese flotante
 * \return El número ingresado por el usuario tipo flotante
 *
 */
int  RangoValidoFlotante(float , int , int );

/**
 * \brief Solicita un número entero usuario que el mismo ingresa como un strnig
 * \param mensaje Es el mensaje a ser mostrado
 * \param el valor minimo para ese entero
  * \param el valor maximo para ese entero
 * \return El número ingresado por el usuario tipo entero
 *
 */

int IngresarEntero(char [], int , int );

/**
* \brief valida un strnig solo numeros
* \param el cadena caracteres
* \param el valor minimo para ese entero
* \param el valor maximo para ese entero
* \return El número ingresado por el usuario tipo entero
*
*/
float validarEntero(char [], int , int , int );

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int validarRangoEntero (int , int , int );

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */



void getString(char [],char [], int , int );


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */



void getStringletras(char [],char [], int , int );

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */



int esTexto(char []);

int esNumero(char []);

int Confirmacion(char []);


void getStringEntero(char [],char [], int , int );






#endif
