#include <iostream>
#include <string>
#include "FechaHistorica.h"
#include "Cronologia.h"
#include <sstream>


using namespace std;

//Función para intercambiar enteros
void swap (int & a, int & b) {
  int x;
  x = a;
  a = b;
  b = x;
}

Cronologia::Cronologia(){}


Cronologia::Cronologia(const Cronologia& c) {
  cron = c.cron;
}


//Ordena
  void Cronologia::ordenar(){
    int n = getNumeroFechas();
     for (int i=n-1; i>0; --i)
      for (int j=0; j<i; ++j) {
         if (cron[j].getYear() > cron[j+1].getYear()) {
            FechaHistorica aux;
            aux = cron[j];
            cron[j] = cron[j+1];
            cron[j+1]= aux;
         }

       }
}

int Cronologia::getNumeroFechas() const {
  return cron.getUtilizados();
}

void Cronologia::addFecha(FechaHistorica f) {
  int i = 0;
  if(getNumeroFechas() == 0)
    cron.addItem(f);
    else  {
      while(i < getNumeroFechas() && f.getYear() > cron[i].getYear())
        i++;

        if(i == getNumeroFechas()) {
          cron.addItem(f);
        }
        else {
          cron.push_back(i);
          cron[i] = f;
        }
    }
}

void Cronologia::setFecha(int i, FechaHistorica f) {
  cron.setItem(i,f);
  ordenar();
}

//Si no es válida la posición, devuelve una fecha vacía
FechaHistorica Cronologia::getFecha(int i) const{
  if(i >= 0 && i < cron.getUtilizados())
    return cron[i];
  FechaHistorica f;
  return f;
}

  //Si no está, devuelve -1
  int Cronologia::findYear(int y) const {
    int n = getNumeroFechas();
    for(int i = 0; i <  n && y >= cron[i].getYear(); i++) {
      if(y == cron[i].getYear())
        return i;
    }
    return -1;
  }

//Si el año no está, devuelve una fecha vacía
FechaHistorica Cronologia::getEventsYear(int y) const {
  int pos = findYear(y);
  if(pos != -1)
    return cron[pos];
  FechaHistorica f(y);
  return f;
}

Cronologia Cronologia::EventsBetween(int y1, int y2) {
  if(y1 > y2)
    swap(y1,y2);

  Cronologia cr;
  int n = getNumeroFechas();
  if(y1 <= cron[n-1].getYear() &&  y2 >= cron[0].getYear()) {
    //Buscamos dónde empezamos, en la posición mayor o igual a y1
    int i = 0;
    while(y1 > cron[i].getYear())
      i++;
    for(int j = i; y2 >= cron[j].getYear() && j < n; j++)
      cr.addFecha(cron[j]);
    }
    return cr;
}

bool Cronologia::BuscarEventos(string s, Cronologia &matches) {
  int n = getNumeroFechas();
  for(int i = 0; i < n; i++) {
    FechaHistorica f;
    bool existe = cron[i].buscarEventos(s,f);
    if(existe)
      matches.addFecha(f);
  }
  return (matches.getNumeroFechas() > 0);
}

Cronologia& Cronologia::operator=(const Cronologia& nuevo) {
  if(&nuevo != this) {
    cron = nuevo.cron;
  }
  return *this;
}

  ostream& operator<< (ostream& os, const Cronologia& c) {
    int n = c.getNumeroFechas();
    for(int i = 0; i < n; i++)
      os << c.cron[i] << endl;
    return os;
    }

  istream& operator>> (istream& is, Cronologia& c) {
    string aux;
    while(!is.eof()) {
      getline(is,aux,'\n');
      if(!aux.empty()) {
        FechaHistorica faux;
          istringstream ss(aux);
        ss >> faux;
        c.addFecha(faux);
      }
    }
    return is;
  }
