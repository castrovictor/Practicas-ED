#ifndef __PILA_MAX_COLA_H__
#define __PILA_MAX_COLA_H__

#include<cola.h>

struct elemento {
  int dato;
  int max;
};

class PilaMax {
private:
  Cola<elemento> pila;

 public:
  PilaMax(){};

  PilaMax(const PilaMax & copia): pila(copia.pila) {};

  PilaMax& operator=(const PilaMax& otra);

  int getUsed() const;

  bool empty() const;

  void push(int elem);

  void pop();

  elemento& top();

  const elemento& top() const;

};

#endif
