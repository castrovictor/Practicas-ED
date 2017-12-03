#include "FechaHistorica.h"
#include <sstream>
#include <string>
#include <ostream>
#include <iostream>


typedef set<string>::iterator iterador;
typedef set<string>::const_iterator const_iterator;

const char SEP = '#';

FechaHistorica::FechaHistorica(const FechaHistorica& f) {
  year = f.year;
  eventos = f.eventos;
 }

  int FechaHistorica::getYear() const{
    return year;
  }


  int FechaHistorica::getUtilizados() const {
    return eventos.size();
  }

  void FechaHistorica::setYear(int y) {
    year = y;
  }

  void FechaHistorica::addEvento(string nuevo) {
    eventos.insert(nuevo);
  }

  void FechaHistorica::addEventos(const FechaHistorica& h){
    for(iterador i = h.eventos.begin(); i != h.eventos.end(); ++i)
      eventos.insert(*i);
  }

  bool FechaHistorica::existEvento(string s) const {
    return eventos.count(s);
  }

  bool FechaHistorica::buscarEventos(string s, FechaHistorica &matches){
    bool encontrado = false;
    for (iterador p = eventos.begin(); p != eventos.end(); ++p) {
       if(p->find(s) != -1 ) {
          matches.addEvento(*p);
          encontrado = true;
       }
    }
    if (encontrado)
       matches.year=year;

    return encontrado;
}


ostream& operator<< (ostream& os, const FechaHistorica& e) {
    os << e.getYear();

    for(const_iterator p = e.eventos.begin(); p != e.eventos.end(); ++p)
    	os << SEP << *p << flush;


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
