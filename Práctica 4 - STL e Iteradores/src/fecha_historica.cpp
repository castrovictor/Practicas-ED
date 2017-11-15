#include "fecha_historica.h"

typedef typename set<string>::iterator iterator;
typedef typename set<string>::const_iterator const_iterator;

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

  bool FechaHistorica::existEvento(string s) const {
    return eventos.count(s);
  }

  bool FechaHistorica::buscarEventos(string s, FechaHistorica &matches){
    bool encontrado = false;
    const_iterator inicio = eventos.begin();
    const_iterator fin = eventos.end();
    for (const_iterator p = inicio; p != fin; ++p) {
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
    const_iterator inicio = e.eventos.begin();
    const_iterator fin = e.eventos.end();
    for(const_iterator p = inicio; p != fin; ++p)
      os << SEP << *p;
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
