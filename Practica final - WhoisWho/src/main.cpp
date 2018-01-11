#include <fstream>
#include <iostream>
#include <string>
#include <math.h>

#include "../include/quienesquien.h"

using namespace std;

int main(int argc, char * argv[]){

	bool jugar = false;
	bool limpiar = false;
	QuienEsQuien quienEsQuien;

	if(argc == 2){
		string parametroAleatorio = "aleatorio";
		if(argv[1]== parametroAleatorio){
			cout << "Creando un QuienEsQuien aleatorio"<< endl;
			int numero_de_personajes;
		   	int numero_de_atributos;

		   	do{
		   		cout << "¿Número de personajes? ";
		   		cin >>numero_de_personajes;
		   	}while(numero_de_personajes<=0);

		   	quienEsQuien.tablero_aleatorio(numero_de_personajes);

		   	string nombreFicheroSalida = string("datos/tablero") +
		   		"-num-per="+to_string(numero_de_personajes);

		   	cout << "Guardando tablero aleatorio en "<<nombreFicheroSalida<<endl;
		   	ofstream archivoDeSalida(nombreFicheroSalida);
		   	archivoDeSalida << quienEsQuien;

		   	cout << "Guardado"<<endl;
		   	return 0;

		}else{
			cout << "Cargando fichero para jugar'"<< argv[1] <<"'"<< endl;
			ifstream f (argv[1]);
			if (!f){
				cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
				return 1;
			}
			f>> quienEsQuien;
			jugar = true;
		}
	} else if(argc == 3 ){
		string parametroLimpiar = "limpiar";
		if(parametroLimpiar== argv[2]){
			cout << "Cargando fichero para limpiar (sin jugar) '"<< argv[1] <<"'"<< endl;
			ifstream f (argv[1]);
			if (!f){
				cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
				return 1;
			}
			f>> quienEsQuien;
			jugar = false;
		} else{
			cout << "Modo '"<<argv[2]<<"' no reconocido"<<endl;
			return 1;
		}

	} else {
		cout << "No se reconocen los argumentos. Ejemplos de uso:" << endl;
		cout << "\tJugar:               ./bin/quienesquien RUTA_FICHERO"<< endl;
		cout << "\tLimpiar sin jugar:   ./bin/quienesquien RUTA_FICHERO limpiar"<< endl;
		cout << "\tGenerar aleatorio:   ./bin/quienesquien aleatorio"<< endl;
		return 1;
	}

	char m;
	cout << "¿Desea el modo de juego mejorado (preguntas optimizadas) (S/N)?: ";
	cin >> m;
	m = toupper(m);
	while(m != 'S' && m != 'N') {
		cout << endl;
		cout << "Opción incorrecta, s (sí) o n (no):";
		cin >> m;
		m = toupper(m);
	}

	//Por defecto lo hace mejorado
	if(m == 'N')
		quienEsQuien.set_modo_juego(0);


	quienEsQuien.mostrar_estructuras_leidas();
	quienEsQuien.usar_arbol(quienEsQuien.crear_arbol());

	cout << "=========== Arbol en crudo ===========" << endl;
	quienEsQuien.escribir_arbol_completo();

	cout << "Profundidad promedio de las hojas del arbol: ";
	cout << quienEsQuien.profundidad_promedio_hojas() << endl;
	cout << "======================================" << endl << endl << endl;

	quienEsQuien.eliminar_nodos_redundantes();

	cout << "=========== Arbol ===================="<<endl;
	quienEsQuien.escribir_arbol_completo();
	cout << "Profundidad promedio de las hojas del arbol: ";
	cout << quienEsQuien.profundidad_promedio_hojas()<<endl;
	cout << "======================================" << endl << endl << endl;

	//Aquí preguntamos por un nuevo personaje
	char np;
	cout << "¿Desea añadir un nuevo personaje? (S/N): ";
	cin >> np;
	np = toupper(np);
	while(np != 'S' && np != 'N') {
		cout << endl;
		cout << "Opción incorrecta, s (sí) o n (no): ";
		cin >> np;
		np = toupper(np);
	}
	


	if(np == 'S') {
		string personaje_nuevo;
		vector<bool> nuevo;
		cout << "Ingrese el nombre del personaje a añadir: ";
		cin >> personaje_nuevo;
		int n = quienEsQuien.numero_de_atributos();
		for(int i = 0; i <n; i++) {
			char aux;
			cout << "¿Tiene el " << i << "º atributo? (S/N): ";
			cin >> aux;
			aux = toupper(aux);
			while(aux != 'S' && aux != 'N') {
				cout << endl;
				cout << "Opción incorrecta, s (sí) o n (no): ";
				cin >> aux;
				aux = toupper(aux);
			}
			if(aux == 'S')
				nuevo.push_back(1);
			if(aux == 'N')
				nuevo.push_back(0);
		}
		quienEsQuien.aniade_personaje(personaje_nuevo, nuevo);
		cout << "El personaje ha sido añadido." << endl;
	}
	
	//Preguntamos si quieres borrar algún personaje
	char bp;
	cout << "¿Deseas borrar algun personaje? (S/N): ";
	cin >> bp;
	bp = toupper(bp);
	while(bp != 'S' && bp != 'N') {
		cout << endl;
		cout << "Opción incorrecta, s (sí) o n (no): ";
		cin >> bp;
		bp = toupper(bp);
	}
	
	if( bp == 'S'){
		string personaje_borrar;
		cout << "Ingrese el nombre del personaje que quieres borrar: ";
		cin >> personaje_borrar;
		quienEsQuien.elimina_personaje(personaje_borrar);
	}


	cout << "\n=========== Arbol ===================="<<endl;
	quienEsQuien.escribir_arbol_completo();
	cout << "Profundidad promedio de las hojas del arbol: ";
	cout << quienEsQuien.profundidad_promedio_hojas()<<endl;
	cout << "======================================" << endl << endl << endl;

	if(quienEsQuien.modo_juego())
		cout << "Se está jugando con el árbol de respuestas optimizado. " << endl;
	else
		cout << "Se está jugando con el árbol de respuestas sin optimizar. " << endl;

	if(jugar){
		quienEsQuien.iniciar_juego();
	}

}
