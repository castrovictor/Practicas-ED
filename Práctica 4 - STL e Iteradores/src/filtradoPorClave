#include "cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
  string clave;

  if (argc > 4){
      cout<<"Demasiados argumentos"<<endl;
      return 0;
   }

   if(argc == 1){
      cout<< "Necesito una cronología" << endl;
      return 0;
     }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }


   Cronologia cron, busqueda;

   f >> cron;

  if(argc >= 3)
    clave = argv[2];
  else {
    cout << "Introduce una clave: ";
    cin >> clave;
  }

  cron.BuscarEventos(clave,busqueda);

  if(argc == 4){
    ofstream salida (argv[3]);
    salida << busqueda;
  }

  else
    cout << busqueda;

}
