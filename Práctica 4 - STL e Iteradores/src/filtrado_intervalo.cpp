#include "cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc < 4){
      cout<<"Número de argumentos inválido, proporcionar fichero, límite inferior, límite superior y fichero para guardar la cronología(opcional)."<<endl;
      return 0;
   }



   ifstream f (argv[1]);
   if (!f){
    cout<<"No ha sido posible abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   Cronologia mi_cronologia;
   f >> mi_cronologia;

   int nyears = mi_cronologia.getNumeroFechas();
   int neventos = mi_cronologia.getNumeroEventos();
   int nmax = mi_cronologia.getMaximoEventos();
   int promedio = neventos / nyears;

   cout << "El número total de años es " << nyears << endl;
   cout << "El número total de eventos guardados es " << neventos << endl;
   cout << "El máximo de eventos por año es " << nmax << endl;
   cout << "El promedio de eventos por año es " << promedio;


}
