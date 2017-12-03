#ifndef _fecha_historica_h_
#define _fecha_historica_h_

#include <set>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;


typedef set<string>::iterator iterador;
typedef set<string>::const_iterator const_iterator;


class FechaHistorica {
private:
  set<string> eventos;      /**Set de strings con los eventos */
  int year;                 /**Año en el que ocurrieron los eventos */

public:

   /**
  * @brief Constructor vacío, inicia el año en 0 y el set vacío.
  */
  FechaHistorica(): year(0) {}

  /**
  * @brief Constructor copia, inicia la nueva fecha con los mismo datos que la del argumento
  * @param f FechaHistorica con los datos a copiar
  */

  FechaHistorica(const FechaHistorica& f);

    /**
  * @brief Constructor copia, inicia la nueva fecha con los mismo datos que la del argumento
  * @param y int del año en el que ocurrieron los eventos
  * @param v set<string> con los eventos históricos
  */

  FechaHistorica(int y, set<string> v): eventos(v), year(y) {};

  iterador begin();

  const_iterator end();

  iterador end();

  const_iterator end() const;

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
    * @brief Añade los eventos de la fecha del argumento
    * @param h FechaHitorica con los nuevos eventos
    */

  void addEventos(const FechaHistorica& h);

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
