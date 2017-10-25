#include <iostream>
#include <cassert>
using namespace std;

bool PilaMax::empty() const {
  return pila.getUtilizados() == 0;
}

int PilaMax::getUsed() const {
  return pila.getUtilizados();
}


void PilaMax::push(int elem) {
  elemento aux;
  aux.dato = elem;

  if(empty()) {
    aux.max = elem;
  } else {
    int id = getUsed()-1;
    if(pila[id] > elem)
      elem = pila[id];
    aux.max = elem;
  }
  pila.addItem(aux);
}

void PilaMax::pop() {
  int id = getUsed() -1;
  pila.deleteItem(id);
}

elemento PilaMax::top() {
  assert(!empty());
  return pila[getUsed()-1];
}
