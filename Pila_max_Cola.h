#ifndef __PILA_MAX_COLA_H__
#define __PILA_MAX_Cola_H__

#include<cola.h>

struct elemento {
  int dato;
  int max;
};

class PilaMaxCola(){
private:
  Cola<elemento> pila;
  
 public:
  PilaMaxCola(){};

  PilaMaxCola(const PilaMaxCola & copia): pila(copia.pila) {};
   
  PilaMaxCola& operator=(const PilaMax& otra);
  
  int getUsed() const;

  bool empty() const;

  void push(elemento insertado);

  void pop();

  elemento& top();
  
  const elemento& top() const;
  
 }
  
