#include "FechaHistorica.h"
#include "cronologia.h"
#include <sstream>



using namespace std;

typedef pair<int,FechaHistorica> par;
typedef map<int, FechaHistorica>::iterator it;
typedef map<int, FechaHistorica>::const_iterator const_iterator;
typedef set<string>::const_iterator const_iterator_set;



//Función para intercambiar enteros
void swap (int & a, int & b) {
  int x;
  x = a;
  a = b;
  b = x;
}


void UnirCronologias(const Cronologia& c1, const Cronologia& c2, Cronologia& res) {
  res = c1;
  for(const_iterator p = c2.cron.begin(); p != c2.cron.end(); ++p) {
    int y = p->first;
    if(c1.cron.count(y)) {
      FechaHistorica faux;
      faux.setYear(y);
      faux.addEventos(c1.cron.find(y)->second);
      faux.addEventos(c2.cron.find(y)->second);
      res.cron.erase(y);
      res.addFecha(faux);
    } else
      res.addFecha(p->second);
    }
}

Cronologia::Cronologia(){}


Cronologia::Cronologia(const Cronologia& c) {
  cron = c.cron;
}


int Cronologia::getNumeroFechas() const {
  return cron.size();
}

int Cronologia::getNumeroEventos() const {
  int n = 0;
  for(const_iterator p = cron.begin(); p != cron.end(); ++p)
    n += p->second.getUtilizados();

  return n;
}

int Cronologia::getMaximoEventos() const {
  int max = 0;
  for(const_iterator p = cron.begin(); p != cron.end(); ++p)
    if(p->second.getUtilizados() >= max)
      max = p->second.getUtilizados();

  return max;
}

void Cronologia::addFecha(FechaHistorica f) {
	cron.insert(par(f.getYear(),f));
}

void Cronologia::deleteFecha(int y) {
  cron.erase(y);

}

//Si no es válida la posición, devuelve una fecha vacía
FechaHistorica Cronologia::getFecha(int y) const{
	if(existYear(y))
		return cron.find(y)->second;

	FechaHistorica f;
	return f;
}

  //Si no está, devuelve 0
bool Cronologia::existYear(int y) const {
	return cron.count(y);
}


Cronologia Cronologia::EventsBetween(int y1, int y2) {
  if(y1 > y2)
    swap(y1,y2);

	//Buscamos el año mayor o igual que y1
	bool encontrado = false;
	int lowerYear;
	Cronologia cr;
	for(int i = y1; i <= y2 && !encontrado; ++i)
		if(existYear(i)) {
			encontrado = true;
			lowerYear = i;
		}

	if(encontrado) {
		encontrado = false;
		int greaterYear;
		for(int i = y2; i >= lowerYear && !encontrado; --i)
			if(existYear(i)) {
				encontrado = true;
				greaterYear = i;
			}

		for(it p = cron.find(lowerYear); p != cron.find(greaterYear); ++p)
			cr.addFecha(p->second);

		cr.addFecha(cron.find(greaterYear)->second);

	}
    return cr;
}

bool Cronologia::BuscarEventos(string s, Cronologia &matches) {
  int n = getNumeroFechas();
  for(it p = cron.begin(); p != cron.end(); ++p) {
    FechaHistorica f;
    bool existe = p->second.buscarEventos(s,f);
    if(existe)
      matches.addFecha(f);
  }
  return (matches.getNumeroFechas() > 0);
}

Cronologia& Cronologia::operator=(const Cronologia& nuevo) {
  if(&nuevo != this)
    cron = nuevo.cron;

  return *this;
}

  ostream& operator<< (ostream& os, const Cronologia& c) {

    for(const_iterator p = c.cron.begin(); p != c.cron.end(); ++p) {
      os << p->second << endl;
    }
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
