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


 void PilaMax::push(elemento insertado) {
   pila.poner(insertado);
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
     aux.quitar()

   return aux.frente();
 }


 const elemento& top() const {
   Cola<elemento> aux;
   aux = pila;

   int n = getUsed();
   for(int i = 1; i < n; i++)
     aux.quitar();
   return aux.frente();

 }
