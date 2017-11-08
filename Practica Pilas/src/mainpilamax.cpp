#include <iostream>
#include "Pila_max_Cola.h"
using namespace std;

int main() {
  PilaMax pila1;

  pila1.push(1);
  cout << pila1.top().dato << "Max: " << pila1.top().max << endl;
  pila1.push(3);
  cout << pila1.top().dato << "Max: " << pila1.top().max << endl;
  pila1.push(2);
  cout << pila1.top().dato << "Max: " << pila1.top().max << endl;

/*
  pila1.pop();
  cout << pila1.top().dato << "Max: " << pila1.top().max << endl;
  pila1.pop();
  cout << pila1.top().dato << "Max: " << pila1.top().max << endl;
  pila1.pop();
*/
  PilaMax pila2(pila1);
cout << "Pila2" << endl;
  cout << pila2.top().dato << "Max: " << pila2.top().max << endl;
  pila2.pop();
  cout << pila2.top().dato << "Max: " << pila2.top().max << endl;
  pila2.pop();
  cout << pila2.top().dato << "Max: " << pila2.top().max << endl;


}
