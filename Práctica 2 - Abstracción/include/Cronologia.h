/**
  * @file Cronologia.h
  * @brief Fichero cabecera del TDA Cronologia
  *
  */

#ifndef _CRONOLOGIA_
#define _CRONOLOGIA_

#include <iostream>
#include <string>
#include "FechaHistorica.h"

using namespace std;

/**
  *  @brief T.D.A. Cronologia
  *
  * Una instancia @e c del tipo de datos abstracto @c Cronologia es un objeto
  * con 1 campo, un vector dinámico de objetos de FechaHistorica
  *
  * @author  Maxi Suárez van Gelderen
  * @author Victor Castro Serrano
  * @date
  */


class Cronologia {
private:
  VectorDin<FechaHistorica> cron;  /**< Vector dinamico de FechasHistoricas */
  void ordenar();             /**< Función privada para ordener los eventos según la fecha */

public:
  /**
    * @brief Constructor por defecto de la clase. Lo creamos sencillamente para evitar
    * errores o asignaciones de basura a objetos de nuestra clase. Crea una Cronologia
    * por defecto con año 0, con el vector vacío..
    */
  Cronologia();

  /**
    * @brief Constructor copia de la clase
    *@param c objeto cronología del que se copia la información
    */

Cronologia(const Cronologia& c);

  /**
    * @brief Nos devuelve el número de FechasHistoricas que tiene nuestra cronología
    *@return Número de FechasHistoricas que tiene nuestra cronología
    */
  int getNumeroFechas() const;

  /**
    *@brief Devuelve la FechaHistorica que contiene nuestro
    *vector cronologico en la posicion i
    *@param i posicion
    *@return Devuelve la FechaHistorica que contiene nuestro
    */
  FechaHistorica getFecha(int i) const;

  /**
    *@brief Añade una FechaHistórica ordenadamente
    *@param f FechaHistorica que se queire añadir
    */
  void addFecha(FechaHistorica f);

  /**
    *@brief Sobreescribe una fecha ya existente y la ordena cronológicamente
    *@param i posición donde se quiere insertar la fecha
    *@param f FechaHistorica que se queire añadir
    */

  void setFecha(int i, FechaHistorica f);

  /**
    *@brief Devuelve la FechaHistorica y los acontecimientos que ocurrieron
    *en un año especifico, si no se encuentra en nuestra cronologia devuelve un
    *FechaHistorica de ese año sin eventos.
    *@param y Año que quieres buscar
    *@return Devuelve la FechaHistorica y los acontecimientos que ocurrieron
    */
  FechaHistorica getEventsYear(int y) const;

  /**
    *@brief Busca un año en la cronología y devuelve la posicion del vector
    *cron en la que se encuentra.
    *@param f Año que se quiere buscar
    *@return Devuelve posicion del vector del año. Si no está, devuelve -1
    */
  int findYear(int f) const;


  /**
    *@brief Busca los acontecimientos que ocurrieron entre dos años
    *@param y1 primer año
    *@param y2 segundo año
    *@return Devuelve una cronologia que contiene los acontecimientos entre ambos años
    */
  Cronologia EventsBetween(int y1, int y2);

  /**
    *@brief Busca los acontecimientos que ocurrieron entre dos años
    *@param s string que contiene el evento a buscar
    *@param matches Cronologia devuelta por referencia donde se almacenará la Cronologia de eventos buscados
    *@return Devuelve un bool indicando si estaba el evento en la cronología
    */

  bool BuscarEventos(string s, Cronologia &matches);

  /**
    * @brief Sobrecarga del operador =. Permite igualar una crnología a otra
    * @param nuevo Cronologia al que se quiere igualar
    */
  Cronologia& operator=(const Cronologia& nuevo);

  /**
    *@brief Sobrecarga del operador <<
    *@param os Flujo al que queremos volcar nuestra cronología
    *@param c Cronología que queremos volcar
    */

  friend ostream& operator<< (ostream& os, const Cronologia& c);

  /**
    *@brief Sobrecarga del operador >>. Comprueba si hay saltos de línea vacíos en el fichero para evitar que lo tome como una fecha.
    *@param is Flujo del que queremos cargar la cronología
    *@param c Cronología donde queremos cargar el Flujo
    */
  friend istream& operator>> (istream& is, Cronologia& c);




};
#endif
