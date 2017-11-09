#include<iostream>
#include<cassert>
#include<Pila_max_Cola.h>

using namespace std;

PilaMax& PilaMax::operator=(const PilaMax& otra){
  pila = otra.pila;
 }


 int PilaMax::getUsed() const {
   return pila.num_elementos();
 }

 bool PilaMax::empty() const {
   return pila.vacia();
 }

 void PilaMax::push(int elem) {
   elemento aux;
   aux.dato = elem;

   if(empty()) {
     aux.max = elem;
     pila.poner(aux);
   } else {
    if(pila.frente().max > elem) {
      elem = pila.frente().max;
    }
    aux.max = elem;

    Cola<elemento> aux1;
    aux1.poner(aux);
    for(int i=0; i < getUsed(); i++){
       aux1.poner(pila.frente());
       pila.quitar();
    }
      pila = aux1;
  }
 }



 void PilaMax::pop() {
   pila.quitar();
 }


 elemento& PilaMax::top() {
   return pila.frente();
 }


 const elemento& PilaMax::top() const {
   pila.frente();
 }
