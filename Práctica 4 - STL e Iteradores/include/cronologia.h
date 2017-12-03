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
#include <map>

using namespace std;

typedef pair<int,FechaHistorica> par;
typedef map<int, FechaHistorica>::iterator it;
typedef map<int, FechaHistorica>::const_iterator const_iterador;
typedef set<string>::const_iterator const_iterator_set;


/**
  *  @brief T.D.A. Cronologia
  *
  * Una instancia @e c del tipo de datos abstracto @c Cronologia es un objeto
  * con 1 campo, un map<int,FechaHistorica> con los años y los eventos históricos correspondientes
  *
  * @author  Maxi Suárez van Gelderen
  * @author  Victor Castro Serrano
  * @date
  */


class Cronologia {
private:
  map<int,FechaHistorica> cron;     /**< map de las fechas históricas */

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
    * @brief Nos devuelve el número total de eventos históricos almacenados en la cronología
    * @return Número de eventos histricos que tiene la cronologa
    */

  int getNumeroEventos() const;

  /**
    * @brief Nos devuelve el mayor número de eventos almacenados para un año
    * @return Mayor número de eventos almacenados para un año
    */

  int getMaximoEventos() const;

  /**
    *@brief Devuelve la FechaHistorica que contiene nuestro
    *vector cronologico en la posicion i
    *@param i posicion
    *@return Devuelve la FechaHistorica que contiene nuestro
    */
  FechaHistorica getFecha(int i) const;

  /**
    *@brief Añade una FechaHistórica ordenadamente
    *@param f FechaHistorica que se quiere añadir
    */
  void addFecha(FechaHistorica f);

  /**
    *@brief Borra la FechaHistorica correspondiente con el año del argumento
    *@param y Año de los eventos a borrar
    */

  void deleteFecha(int y);


  /**
    *@brief Devuelve si existe una FechaHistorica con el año dado como argumento
    *@param f Año que se quiere buscar
    *@return bool en verdadero si existe la FechaHistorica con el año dado
    */
  bool existYear(int f) const;


  /**
    *@brief Busca los acontecimientos que ocurrieron entre dos años
    *@param y1 primer año
    *@param y2 segundo año
    *@return Devuelve una cronologia que contiene los acontecimientos entre ambos años
    */
  Cronologia EventsBetween(int y1, int y2);

  /**
    *@brief Busca los acontecimientos que contengan el string dado como argumento
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

 /**
    *@brief Dadas dos cronologiaas, las une y las almacena en la tercera dada como argumento por referencia
    *@param c1 Primera cronología a unir
    *@param c2 Segunda cronología a unir
    *@param res Cronología que contendrá la unión de ambas, devuelta por referencia
    */

  friend void UnirCronologias(const Cronologia& c1, const Cronologia& c2, Cronologia& res);



};
#endif
