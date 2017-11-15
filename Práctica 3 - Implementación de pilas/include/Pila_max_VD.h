/**
  * @file Pila_max_VD.h
  * @brief Fichero cabecera de la pila implementada con un vector dinámico de la clase "vectordin"
*/

#ifndef __PILA_MAX_VD__
#define __PILA_MAX_VD__

#include "vectordin.h"


struct elemento {
  int dato;
  int max;
};

/**
  *  @brief T.D.A. Pila a partir de vector dinámico
  *
  * Una instancia @e p del tipo de datos abstracto @p PilaMax es un objeto
  * con 1 campo, un vector dinámico del dato estrcuturado elemento
  *
  * @author  Víctor Castro Serrano
  * @author Maximino Suárez van Gelderen
  * @date
  */


class PilaMax {
private:
  VectorDin<elemento> pila;

public:

  /**
    * @brief Constructor por defecto de la clase. Lo creamos sencillamente para evitar
    * errores o asignaciones de basura a objetos de nuestra clase. Crea una PialMAx
    * con un el vector de elementos vacío.
    */
  PilaMax() {};

  /**
  * @brief Constructor copia de la clase
  *@param p objeto PilaMax del que se copia la información
  */

  PilaMax(const PilaMax & copia): pila(copia.pila) {};

  /**
   * @brief Sobrecarga del operador =. Permite igualar una pila a otra
   * @param otra PilaMax al que se quiere igualar
   */

  PilaMax& operator=(const PilaMax& otra);

  /**
    * @brief Nos devuelve el número de elementos que tiene nuestra pila
    *@return Número de elemenetos que tiene nuestra pila
    */
  int getUsed() const;

  /**
    * @brief Nos devuelve si la pila se encuentra vacía o no
    * @return bool en true si se encuentra vacía
  **/

  bool empty() const;

  /**
   * @brief Inserta un elemento en la pila
   * @param insertado int dato entero que se introduce en la pila
   */

  void push(int insertado);

  /**
   * @brief Elimina el úĺtimo elemento de la pila
   */

  void pop();

  /**
   * @brief Devuelve el último elemento insertado en la pila, no lo elimina.
   * @param elem elemento que se encuentra en el tope de la pila
   */

  elemento& top();

  /**
   * @brief Devuelvolución por referencia constante del último elemento insertado en la pila, no lo elimina.
   * @param elem elemento que se encuentra en el tope de la pila
   */
  const elemento& top() const;
};

#endif
