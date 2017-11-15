/**
  * @file FechaHistorica.h
  * @brief Fichero cabecera del TDA FechaHistorica
  *
  */



#ifndef _FECHAHISTORICA_
#define _FECHAHISTORICA_

#include <iostream>
#include <vectordin.h>
#include <string>


using namespace std;


/**
  *  @brief T.D.A FechaHistorica
  *
  * Una instancia @e c del tipo de datos abstracto @c FechaHistorica es un objeto
  * con dos campos, un @c int que representa el año y un @c vector @c dinámico de @c strings
  * Uno de los enteros es la fecha base del conjunto de eventos y el vector dinámico de strings contendrá
  * los eventos que sucedieron en ese año.
  * Para ver cómo funciona el @c vector @c dinámico, consultar vectordinamio.h
  *
  * @author Maxi Suárez van Gelderen
  * @author Víctor Castro Serrano
  * @date
  */

class FechaHistorica {
private:
  VectorDin<string> eventos; /**< vector de eventos */
  int year;		     /**< año en el que ocurrieron los eventos */

public:

  /**
    * @brief Constructor por defecto de la clase. Lo creamos sencillamente para evitar
    * errores o asignaciones de basura a objetos de nuestra clase. Crea una FechaHistorica
    * por defecto con año 0, con el vector nulo
    */
  FechaHistorica(): year(0) {}

  /**
    * @brief Constructor con un parámetro de la clase. El usuario puede crear una fecha indicando solo el año.
    * @param y año del evento a construir
    * @return Crea el evento con los datos de y, el vector de eventos quedará vacío
    */
  FechaHistorica(int y): year(y) {}

  /**
    *
    * @brief Constructor copia
    * @param f FechaHistorica que se quiere copiar
    * @return Crea el objeto con los datos de f
    */
    FechaHistorica(const FechaHistorica& f){
      year = f.getYear();
      eventos = f.eventos;
    }

  /**
    * @brief Constructor general de la clase. El objeto se crea con el año y el vector de eventos
    * @param y año del evento a construir
    * @param v eventos ocurridos en dicho año
    * @return Crea el evento con los datos de y y los acontecimientos de eventos
    */
  FechaHistorica(int y, VectorDin<string> v): eventos(v), year(y) {};

  /**
  * @brief Método de acceso al año de la FechaHistorica
  * @return int con el valor del campo year
  */
  int getYear() const;

  /**
    * @brief Método de acceso a la cantidad de eventos almacenados en el vector dinámico
    * @return int con el número de eventos almacenados en el vector dinámico
    */
  int getUtilizados() const;

  /**
    * @brief Modifica el año
    * @param y año de los eventos a construir
    */
  void setYear(int y) ;

  /**
    * @brief Añade un evento
    * @param nuevo string con evento a añadir
    */
  void addEvento(string nuevo);

  /**
    * @brief Consulta si existe un evento
    * @param s evento que se desea saber si está
    * @return bool con verdadero si está, false si no se existe
    */
  bool existEvento(string s) const;

  /**
    * @brief Búsqueda de eventos en una Fecha_Historica dada una palabra clave s
    * @param s string con la palabra a buscar
    * @param matches nueva Fecha_Historica donde se introducen únicamente los eventos de this que contienen el string s
    * @return Devuelve true o false indicando si hay o no algún match de la cadena clave s en los eventos de this
    */
  bool buscarEventos(string s, FechaHistorica &matches);

  /**
    * @brief Salida de un FechaHistorica a ostream
    * @param os stream de salida
    * @param e FechaHistorica a escribir
    * @post Se muestra la FechaHistorica en formato "año#evento1#evento2#...#eventon"
    */

  friend ostream& operator<< (ostream& os, const FechaHistorica& e);

  /**
    * @brief Entrada de un FechaHistorica desde istream
    * @param is stream de entrada
    * @param e FechaHistorica que recibe el valor
    * @retval El FechaHistorica leído en e
    * @pre La entrada tiene el formato "año#evento1#evento2#...#eventoN"
    */

  friend istream& operator>> (istream& is, FechaHistorica& e);

  /**
    * @brief Sobrecarga del operador =. Permite igualar una fecha a otra
    * @param nuevo FechaHistorica a la que se quiere igualar
    */

  FechaHistorica& operator=(const FechaHistorica& nuevo);


};
 #endif
