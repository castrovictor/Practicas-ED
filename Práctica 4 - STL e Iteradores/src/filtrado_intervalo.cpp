#include "cronologia.h"
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

int main(int argc, char * argv[]){

  if (argc < 4 || argc > 5){
      cout<<"Número de argumentos inválido, proporcionar fichero, límite inferior, límite superior y fichero para guardar la cronología(opcional)."<<endl;
      return 0;
   }


     ifstream f (argv[1]);
     if (!f){
      cout<<"No ha sido posible abrir el fichero "<<argv[1]<<endl;
      return 0;
     }

     Cronologia mi_cronologia, resultado;
     f >> mi_cronologia;

     int inf = atoi(argv[2]);
     int sup = atoi(argv[3]);


     resultado = mi_cronologia.EventsBetween(inf,sup);

     if(argc == 4) {
     cout << "Los eventos dentro del intervalo son: " << endl;
     cout << resultado << endl;
   } else {
     ofstream f2 (argv[4]);
     if (!f2){
      cout<<"No ha sido posible abrir el fichero "<<argv[4]<<endl;
      return 0;
    }
    f2 << resultado;
  }
}
