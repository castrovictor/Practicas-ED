#ifndef __PILA_MAX_VD__
#define __PILA_MAX_VD__

#include "vectordin.h"


struct elemento {
  int dato;
  int max;
};

class PilaMax {
private:
  VectorDin<elemento> pila;

public:
  PilaMax() {};

  PilaMax(const PilaMax & copia): pila(copia.pila) {};

  PilaMax& operator=(const PilaMax& otra);

  int getUsed() const;

  bool empty() const;

  void push(int insertado);

  void pop();

  elemento& top();

  const elemento& top() const;



};

#endif
