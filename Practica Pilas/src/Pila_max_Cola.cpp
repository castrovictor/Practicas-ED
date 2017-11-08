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
   /*
   elemento aux;
   aux.dato = elem;

   if(empty()) {
     aux.max = elem;
   } else {
     if(top().max > elem) {

       elem = top().max;
     }
     aux.max = elem;
    cout << "El tope es " << top().max << endl;
  }*/
  elemento aux;
  aux.dato = 50;
  aux.max = 30;
  pila.poner(aux);

 }



 void PilaMax::pop() {
  Cola<elemento> aux;
  int n = getUsed();
  for(int i = 1; i < n; i++)
    aux.poner(pila.frente());
  pila = aux;
 }


 elemento& PilaMax::top() {
   Cola<elemento> aux;
   aux = pila;

   int n = getUsed();
   for(int i = 1; i < n; i++)
     aux.quitar();

   return aux.frente();
 }


 const elemento& PilaMax::top() const {
   Cola<elemento> aux;
   aux = pila;

   int n = getUsed();
   for(int i = 1; i < n; i++)
     aux.quitar();
   return aux.frente();

 }
