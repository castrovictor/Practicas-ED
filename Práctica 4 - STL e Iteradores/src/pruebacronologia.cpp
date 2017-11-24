#include "cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=3){
      cout<<"Dime el nombre del fichero con la cronologia"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   ifstream f2 (argv[2]);
   if (!f2){
    cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
    return 0;
   }

   Cronologia mi_cronologia, otra, total;

   f >> mi_cronologia; //Cargamos en memoria
   f2 >> otra;
   UnirCronologias(mi_cronologia,otra,total);

   cout << "Cronología leida del archivo: " << endl << total << endl;

   Cronologia buscadora;


   Cronologia copia(buscadora); //Utilización del constructor de copias

/*
  /* To-do: Ej: buscar un evento y restringir copia a los acontecimientos con ese evento, después imprimir para comprobar
    string cadena = "Sherlock";
    mi_cronologia.BuscarEventos(cadena,copia);
   cout << "Evento encontrado con \"Sherlock\":" << endl << copia;
*/
}
