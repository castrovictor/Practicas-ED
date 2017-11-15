/**
  * @file VectorDin.h
  * @brief Fichero cabecera del TDA VectorDin
  *
  */

#include <iostream>

#ifndef _VECTORDIN_
#define _VECTORDIN_

using namespace std;
/**
  *  @brief T.D.A. VectorDinamico
  *
  * Una instancia @e c del tipo de datos abstracto @c VectorDin es un objeto
  * con 3 campo, un vector dinámico de un objeto template T, y dos int, uno para
  * el número de objetos utiles en el vector y otro con el numero de posiciones
  * reservadas

  
  *
  * @author  Maxi Suárez van Gelderen
  * @author Victor Castro Serrano
  * @date
  */



template <class T>
class VectorDin{
  private:
    int utilizados;                      /**<Int con el número de utilizados */
    int reservados;                      /**<Int con el número de posiciones reservadas */
    T *vect;                             /**<Vector dinámico de objetos T */
    void resize(int n);                  /**<Función bool que redimensiona el vector */
    bool espacio_libre() const;          /**<Función bool que nos dice si hay espacio libre */
    bool posvalida(int pos) const;       /**<Funcion bool que nos dice si es una posicion valida*/

  public:

    /**
      * @brief Constructor vacio, que inicializa todo a 0
      */
    VectorDin();


    /**
      * @brief Destructor de VectorDin
      */
    ~VectorDin();

    /**
      * @brief Destruye el objeto
      */
    void destruir();

    /**
      * @brief Añade un nuevo objeto T al final del vector
      * @param nuevo Objeto T que se quiere añadir
      */
    void addItem(T& nuevo);

    /**
      * @brief Elimina el objeto T de la posicion pos
      * @param pos Posicion donde se encuentra el objeto a borrar
      */
    void deleteItem(int pos);

      /**
        * @brief Sobrecarga constante del operador []
        * @param i Posicion del objeto que se quiere devolver
        */
    T& operator[](int i);

    /**
      * @brief Sobrecarga del operador []
      * @param i Posicion del objeto que se quiere devolver
      */
    const T& operator[](int i) const;


    /**
      *@brief Retrasa los elementos a partir de la posición dada. La componenete pos se queda igual
      *@param pos Posición que queremos dejar libre, retrasando todos los elementos a partir de ella incluída.
      */
    void push_back(int pos);



    /**
      * @brief Constructor de copia
      * @param v Vector que se quiere copiar
      */
    VectorDin(const VectorDin& v);

    /**
      * @brief Devuelve utilizados
      * return Devuelve utilizados
      */
    int getUtilizados() const;

    /**
      * @brief Devuelve reservados
      * @return Devuelve reservados
      */
    int getReservados() const;

    /**
      * @brief Devuelve el objeto de la posicion pos
      * @param pos Posicion del objeto
      * @return Devuelve objeto de la posicion pos
      */
    T getItem(int pos) const;

    /**
      * @brief Inserta un objeto T en la posicion pos
      * @param pos Posicion en la que se quiere insertar
      * @param item Objeto T que se quiere insertar
      */
    void setItem(int pos, T& item);

    /**
      * @brief Nos dice si existe un un elemento
      * @param item Objeto que queremos ver si existItem
      * @return True si existe el objeto
      */
    bool existItem(const T& item) const;

    /**
      * @brief Sobrecarga del operador =
      * @param nuevo Objeto que se va a copiar
      */
    VectorDin<T>& operator=(const VectorDin<T>& nuevo);

};

#include "vectordin.cpp"

#endif
