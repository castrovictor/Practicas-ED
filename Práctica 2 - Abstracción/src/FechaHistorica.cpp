#include <iostream>
#include <FechaHistorica.h>
#include <sstream>
#include <stdlib.h>
#include <string>
using namespace std;

const char SEP = '#';

int FechaHistorica::getYear() const {
  return year;
}

void FechaHistorica::setYear(int y)  {
  year = y;
}

void FechaHistorica::addEvento(string nuevo){
  eventos.addItem(nuevo);
}

bool FechaHistorica::existEvento(string s) const {
  return eventos.existItem(s);
}

int FechaHistorica::getUtilizados() const {
  return eventos.getUtilizados();
}

bool FechaHistorica::buscarEventos(string s, FechaHistorica &matches){
  bool encontrado = false;
  int n = getUtilizados();
  for (int i=0; i < n; ++i) {
     if(eventos[i].find(s) != -1 ) {
        matches.addEvento(eventos[i]);
        encontrado = true;
     }
  }

  if (encontrado)
     matches.year=year;
   
 return encontrado;
}

ostream& operator<< (ostream& os, const FechaHistorica& e) {
    os << e.getYear();
    int n = e.eventos.getUtilizados();
    for(int i = 0; i < n; i++)
      os << SEP << e.eventos[i];
    return os;
}

istream& operator>> (istream& is, FechaHistorica& e)  {
  string aux;
  getline(is, aux, SEP);
  e.year = atoi(aux.c_str());

  while(!is.eof()) {
    getline(is,aux,SEP);
    e.addEvento(aux);
  }
  return is;
}


FechaHistorica& FechaHistorica::operator=(const FechaHistorica& nuevo) {
  if(&nuevo != this) {
    year = nuevo.getYear();
    eventos = nuevo.eventos;
  }
  return *this;
}
