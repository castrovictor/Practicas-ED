#include<iostream>
#include<cassert>
#include<Pila_max_Cola.h>

using namespace std;

PilaMaxCola& PilaMaxCola::operator=(const PilaMaxCola& otra){
  pila = otra.pila;
 }


 int PilaMaxCola::getUsed() const {
   return pila.num_elementos();
 }

 bool PilaMaxCola::empty() const {
   return pila.vacia();
 }


 void PilaMaxCola::push(elemento insertado) {
   Cola<elemento> aux;
   int n = getUsed();
   aux.poner(insertado);
   /*
   Habría que coger un elemento del tope, insertarlo y borrarlo para poder coger del tope otra vez
   */
   for(int i = 1; i <= n; i++) {
     aux.poner(top());
     pila.pop();
   }
   pila = aux;
 }



 void PilaMaxCola::pop() {
  Cola<elemento> aux;
  int n = getUsed();
  for(int i = 1; i < n; i++)
    aux.poner(pila.frente());
  pila = aux;
 }


 elemento& PilaMaxCola::top() {
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
