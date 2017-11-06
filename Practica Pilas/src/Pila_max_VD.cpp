#include <iostream>
#include <cassert>
#include "Pila_max_VD.h"
using namespace std;

bool PilaMax::empty() const {
  return pila.getUtilizados() == 0;
}

int PilaMax::getUsed() const {
  return pila.getUtilizados();
}

PilaMax& operator=(const PilaMax& otra) {
  pila = otra.pila();
}  

void PilaMax::push(int elem) {
  elemento aux;
  aux.dato = elem;

  if(empty()) {
    aux.max = elem;
  } else {
    int id = getUsed()-1;
    if(pila[id].max > elem)
      elem = pila[id].max;
    aux.max = elem;
  }
  pila.addItem(aux);
}

void PilaMax::pop() {
  int id = getUsed() -1;
  pila.deleteItem(id);
}

elemento& PilaMax::top() {
  assert(!empty());
  return pila[getUsed()-1];
}

const elemento& PilaMax::top() const {
  assert(!empty());
  return pila[getUsed()-1];
}
