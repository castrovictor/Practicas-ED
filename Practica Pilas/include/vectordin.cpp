#include <iostream>
#include <vectordin.h>
using namespace std;

template <class T>
VectorDin<T>::VectorDin():reservados(0),utilizados(0),vect(0){}

template <class T>
  bool VectorDin<T>::posvalida(int pos) const{
    return (pos >= 0 && pos < utilizados);
  }

template <class T>
void VectorDin<T>::destruir() {
  reservados = 0;
  utilizados = 0;
  delete [] vect;
  vect = 0;
 }

 template <class T>
VectorDin<T>::~VectorDin() {
  destruir();
}


 //Resize
 template <class T>
   void VectorDin<T>::resize(int n){
      if(n>reservados){
        T *aux = new T[n];
        for (int i=0; i<utilizados; ++i)
           aux[i] = vect[i];
        delete[] vect;
        vect = aux;
        reservados = n;
      }
   }

   template <class T>
   void VectorDin<T>::push_back(int pos) {
     if(pos < getUtilizados() && pos >= 0) {
       if(!espacio_libre())
         resize(2*reservados);

      for(int i = utilizados; i > pos; i--)
        vect[i] = vect[i-1];

        utilizados++;
      }
   }

template <class T>
   bool VectorDin<T>::espacio_libre() const {
     return utilizados < reservados;
   }

template <class T>
  int VectorDin<T>::getUtilizados() const {
    return utilizados;
  }

template <class T>
  int VectorDin<T>::getReservados() const {
    return reservados;
  }

  //Si no es válida la posición, devuelve un T vacío
  template <class T>
  T VectorDin<T>::getItem(int pos) const {
    if(!posvalida(pos)) {
      T t1;
      return t1;
    }
    return vect[pos];
  }

  template <class T>
  T& VectorDin<T>::operator[](int i) {
    return vect[i];
  }

  template <class T>
  const T& VectorDin<T>::operator[](int i) const{
    return vect[i];
  }

template <class T>
  void VectorDin<T>::setItem(int pos, T& item) {
    if(posvalida(pos))
      vect[pos] = item;
  }



 //Añade elemento al vector
  template <class T>
   void VectorDin<T>::addItem(T& nuevo){
      if(!espacio_libre()) {
        if(reservados == 0)
          resize(1);
        else
          resize(reservados*2);
      }
      vect[utilizados]=nuevo;
      utilizados++;
   }

   template <class T>
    void VectorDin<T>::deleteItem(int pos) {
      if(posvalida(pos)) {
        if(pos == 0 && (utilizados == 1))
          destruir();
        for(int i = pos; i < utilizados - 1; i++)
          vect[i] = vect[i+1];
        utilizados--;
      }
    }

    template <class T>
    VectorDin<T>::VectorDin(const VectorDin& v) {
      if(this != &v) {
        utilizados = v.getUtilizados();
        reservados = v.getReservados();
        vect = new T[reservados];
        for(int i = 0; i < utilizados; i++)
          vect[i] = v.getItem(i);
        }
      }

template <class T>
bool VectorDin<T>::existItem(const T& item) const {
  bool encontrado = false;
  for(int i = 0; i < utilizados && !encontrado; i++) {
    if(item == vect[i])
      encontrado = true;
  }

  return encontrado;
}

template <class T>
VectorDin<T>& VectorDin<T>::operator=(const VectorDin<T>& nuevo) {
  if(&nuevo != this) {
    destruir();
    reservados = nuevo.getReservados();
    utilizados = nuevo.getUtilizados();
    vect = new T[reservados];
    for(int i = 0; i < utilizados; i++)
      vect[i] = nuevo.getItem(i);
  }
  return *this;
}
