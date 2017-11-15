#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con la cronologia"<<endl;
      return 0;
   }

   ifstream fentrada (argv[1]);
   if (!fentrada){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   Cronologia prueba;
   fentrada >> prueba;
   cout << prueba;
  

}
