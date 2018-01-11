#include "../include/quienesquien.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>


QuienEsQuien::QuienEsQuien(){}

QuienEsQuien::QuienEsQuien(const QuienEsQuien &quienEsQuien){
	personajes = vector<string>(quienEsQuien.personajes);
	atributos = vector<string>(quienEsQuien.personajes);
	tablero = vector<vector<bool>>(quienEsQuien.tablero);
	arbol = bintree<Pregunta>(quienEsQuien.arbol);
	jugada_actual = arbol.root();
}

QuienEsQuien& QuienEsQuien::operator= (const QuienEsQuien &quienEsQuien){
	if(this != &quienEsQuien){
		limpiar();
		personajes = vector<string>(quienEsQuien.personajes);
		atributos = vector<string>(quienEsQuien.personajes);
		tablero = vector<vector<bool>>(quienEsQuien.tablero);
		arbol = bintree<Pregunta>(quienEsQuien.arbol);
		jugada_actual = arbol.root();
	}
	return *this;
}
QuienEsQuien::~QuienEsQuien(){
	this->limpiar();
}

void QuienEsQuien::limpiar(){
	personajes.clear();
	atributos.clear();
	tablero.clear();
	arbol.clear();
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

void QuienEsQuien::mostrar_estructuras_leidas(){
	cout << "personajes: "<< (this->personajes) << endl;
	cout << "atributos:  "<< (this->atributos)  << endl;
	cout << "tablero:    "<< endl;


	// Escribe la cabecera del tablero
	for(vector<string>::iterator it_atributos = this->atributos.begin();
		it_atributos != this->atributos.end();
		it_atributos++){
		cout << *it_atributos << "\t";
	}
	cout <<endl;

	int indice_personaje = 0;
	for(vector<vector<bool>>::iterator it_tablero_atributos = tablero.begin();
		it_tablero_atributos!= tablero.end();
		it_tablero_atributos++){

		string personaje = this->personajes[indice_personaje];
		int indice_atributo = 0;
		for(vector<bool>::iterator it_atributos_personaje = (*it_tablero_atributos).begin();
			it_atributos_personaje != (*it_tablero_atributos).end();
			it_atributos_personaje++){

			cout << *it_atributos_personaje<<"\t";

			indice_atributo++;
		}

		cout << personaje << endl;

		indice_personaje++;
	}

}

/**
  * @brief Devuelve una copia de la cadena original sin las subcadenas no deseadas.
  *
  * @param cadena_original Cadena de la que se eliminan las subcadenas no deseadas.
  * @param cadena_a_eliminar Subcadena que se busca y se elimina.
  *
  * @return Copia de la cadena original sin las subcadenas no deseadas.
  */
string limpiar_string(string cadena_original,string cadena_a_eliminar){
	string linea(cadena_original);

	while(linea.find_first_of(cadena_a_eliminar) != std::string::npos){
		linea.erase(linea.find_first_of(cadena_a_eliminar),cadena_a_eliminar.length());
	}

	return linea;
}

istream& operator >> (istream& is, QuienEsQuien &quienEsQuien) {
	quienEsQuien.limpiar();

  	if(is.good()){
  		string linea;
    	getline(is, linea, '\n');

    	linea = limpiar_string(linea,"\r");

    	while(linea.find('\t') != string::npos ){
    		string atributo = linea.substr(0,linea.find('\t'));
			quienEsQuien.atributos.push_back(atributo);
    		linea = linea.erase(0,linea.find('\t')+1);
    	}

		assert(linea ==  "Nombre personaje");
	}

    while( is.good() ) {
    	string linea;
    	getline(is, linea, '\n');
    	linea = limpiar_string(linea,"\r");

    	//Si la linea contiene algo extrae el personaje. Si no lo es, la ignora.
    	if(linea != ""){;
	    	vector<bool> atributos_personaje;

	    	int indice_atributo=0;
	    	while(linea.find('\t') != string::npos){
	    		string valor = linea.substr(0,linea.find('\t'));

	    		assert(valor == "0" || valor == "1");

	    		bool valor_atributo = valor == "1";

	    		atributos_personaje.push_back(valor_atributo);

	    		linea = linea.erase(0,linea.find('\t')+1);
	    		indice_atributo++;
			}

			string nombre_personaje = linea;

	    	quienEsQuien.personajes.push_back(nombre_personaje);
	    	quienEsQuien.tablero.push_back(atributos_personaje);
	    }
  	}

	return is;
}

ostream& operator << (ostream& os, const QuienEsQuien &quienEsQuien){

	//Escribimos la cabecera, que contiene los atributos y al final una columna para el nombre
	for(vector<string>::const_iterator it_atributos = quienEsQuien.atributos.begin();
		it_atributos != quienEsQuien.atributos.end();
		it_atributos++){

		os  << *it_atributos << "\t";
	}
	os << "Nombre personaje" << endl;

	//Rellenamos con ceros y unos cada l�nea y al final ponemos el nombre del personaje.
	for(int indice_personaje=0;indice_personaje<quienEsQuien.personajes.size();indice_personaje++){
		for(int indice_atributo=0;indice_atributo<quienEsQuien.personajes.size();indice_atributo++){

			os  << quienEsQuien.tablero[indice_personaje][indice_atributo] << "\t";
		}
		os  << quienEsQuien.personajes[indice_personaje] << endl;
	}

	return os;
}

/**
  * @brief Convierte un n�mero a un vector de bool que corresponde
  *        con su representaci�n en binario con un numero de digitos
  *        fijo.
  *
  * @param n N�mero a convertir en binario.
  * @param digitos N�mero de d�gitos de la representaci�n binaria.
  *
  * @return Vector de booleanos con la representaci�n en binario de @e n
  *      con el n�mero de elementos especificado por @e digitos.

  */
vector<bool> convertir_a_vector_bool(int n, int digitos) {
  vector<bool> ret;
  while(n) {
    if (n&1){
      ret.push_back(true);
    } else{
      ret.push_back(false);
    }
    n>>=1;
  }

  while(ret.size()<digitos){
  	ret.push_back(false);
  }

  reverse(ret.begin(),ret.end());
  return ret;
}


string QuienEsQuien::opcionPregunta(vector<string> atributos, vector<vector<bool>> tablero) {
	int pos = 0;
	if (MODO_MEJORADO == 1) {
		vector<double> proporciones;
		for (int i = 0; i < atributos.size(); ++i) {
			int n_unos = 0;
			for (int j = 0; j < tablero.size(); ++j) {
				if (tablero[j][i])
					++n_unos;
			}
			double media = n_unos * 1.0 / tablero.size();
			proporciones.push_back(abs(media - 0.5));
		}
		pos = distance(proporciones.begin(), min_element(begin(proporciones), end(proporciones)));
	}
	return atributos[pos];
}

// N
void QuienEsQuien::explorarArbol(bintree<Pregunta>& arbol, bintree<Pregunta>::node nodo,
	const vector<string> &personajes, const vector<string> &atributos,
	const vector<vector<bool>> &tablero) {

		string atributoOriginal = (*nodo).obtener_pregunta();
		int pos = distance(atributos.begin(), find(atributos.begin(), atributos.end(), atributoOriginal));

		// Exploramos
		vector<string> personajesSI;
		vector<string> atributosSI(atributos);
		atributosSI.erase(atributosSI.begin() + pos);
		vector<vector<bool>> tableroSI;

		vector<string> personajesNO;
		vector<string> atributosNO(atributos);
		atributosNO.erase(atributosNO.begin() + pos);
		vector<vector<bool>> tableroNO;

		for (int i = 0; i < personajes.size(); ++i) {
			vector<bool> atributosAux(tablero[i]);
			atributosAux.erase(atributosAux.begin() + pos);
			string nombre = personajes[i];
			if (tablero[i][pos]) {
				personajesSI.push_back(nombre);
				tableroSI.push_back(atributosAux);
			} else {
				personajesNO.push_back(nombre);
				tableroNO.push_back(atributosAux);
			}
		}

		int numPersonajes = personajesSI.size();
		if (numPersonajes == 1) {
			arbol.insert_left(nodo, Pregunta(personajesSI[0], 1));
		} else if (numPersonajes > 1) {
			string pregunta =  opcionPregunta(atributosSI, tableroSI);
			arbol.insert_left(nodo, Pregunta(pregunta, numPersonajes));
			explorarArbol(arbol, nodo.left(), personajesSI, atributosSI, tableroSI);
		}

		numPersonajes = personajesNO.size();
		if (numPersonajes == 1) {
			arbol.insert_right(nodo, Pregunta(personajesNO[0], 1));
		} else if (numPersonajes > 1) {
			string pregunta =  opcionPregunta(atributosNO, tableroNO);
			arbol.insert_right(nodo, Pregunta(pregunta, numPersonajes));
			explorarArbol(arbol, nodo.right(), personajesNO, atributosNO, tableroNO);
		}
	}

bintree<Pregunta> QuienEsQuien::crear_arbol()
{
	bintree<Pregunta> arbolNuevo;
	int numPersonajes = personajes.size();
	if (numPersonajes == 1)
		arbolNuevo = bintree<Pregunta>(Pregunta(personajes[0], 1));
	else if (numPersonajes > 1) {
		arbolNuevo = bintree<Pregunta>(Pregunta(opcionPregunta(atributos, tablero), numPersonajes));
		explorarArbol(arbolNuevo, arbolNuevo.root(), personajes, atributos, tablero);
	}
	return arbolNuevo;
}

void QuienEsQuien::usar_arbol(bintree<Pregunta> arbol_nuevo){
	arbol = arbol_nuevo;
}

void QuienEsQuien::iniciar_juego(){
	//usar_arbol(crear_arbol());
	char seguir_jugando = 'S';


	while( seguir_jugando == 'S' ){
		jugada_actual = arbol.root();

		while( (*jugada_actual).es_pregunta() ){
			char resp;

			cout << "Los posibles personajes son:" << endl;
			set<string> personajes = informacion_jugada(jugada_actual);
			for(set<string>::iterator it = personajes.begin(); it != personajes.end(); it++)
				cout << *it << " ";
			cout << "\n";

			cout << endl << "¿Es " << (*jugada_actual).obtener_pregunta() << "?" << endl;
			cout << "Respuesta (S/N): ";
			cin >> resp;
			resp = toupper(resp);

			switch (resp) {
				case 'S':
					jugada_actual = jugada_actual.left();
					break;
				case 'N':
					jugada_actual = jugada_actual.right();
					break;
				default:
					cout << "Respuesta inválida: Sí 'S', No 'N'" << endl;
				}
		}
		cout << "\nEl personaje es " << (*jugada_actual).obtener_personaje() << endl;

		cout << "\nListado de preguntas y respuestas realizado: " << endl;
		stack<pair<string,string>> pila = preguntas_formuladas(jugada_actual);
		while(!pila.empty()) {
			cout << pila.top().first << " : " << pila.top().second<< endl;
			pila.pop();
		}

		cout << endl << "¿Quieres seguir jugando? (S/N)" << endl;
		cin >> seguir_jugando;
		seguir_jugando = toupper(seguir_jugando);
		while (seguir_jugando != 'S' && seguir_jugando != 'N') {
			cout << "Letra no válida, prueba de nuevo (S/N): ";
			cin >> seguir_jugando;
		}
	}
 }

void QuienEsQuien::buscar_personajes(set<string>& personajes, bintree<Pregunta>::node nodo) {
	if (!nodo.left().null())
		buscar_personajes(personajes, nodo.left());
	if (!nodo.right().null())
		buscar_personajes(personajes, nodo.right());
	if ((*nodo).es_personaje())
		personajes.insert((*nodo).obtener_personaje());
}

set<string> QuienEsQuien::informacion_jugada(bintree<Pregunta>::node jugada_actual){
	set<string> personajes_levantados;

	if (jugada_actual == arbol.root()) {
		for (auto it = personajes.begin(); it != personajes.end(); ++it)
			personajes_levantados.insert(*it);
	} else {
		buscar_personajes(personajes_levantados, jugada_actual);
	}

	return personajes_levantados;
}

void escribir_esquema_arbol(ostream& ss,
					  const bintree<Pregunta>& a,
		    		  bintree<Pregunta>::node n,
					  string& pre){
	if (n.null()){
	    ss << pre << "-- x" << endl;
	} else {
	    ss << pre << "-- " << (*n) << endl;
	    if ( !n.right().null() || !n.left().null()) {// Si no es una hoja
			pre += "   |";
	    	escribir_esquema_arbol(ss,a, n.right(), pre);
	     	pre.replace(pre.size()-4, 4, "    ");
	      	escribir_esquema_arbol (ss,a, n.left(), pre);
	      	pre.erase(pre.size()-4, 4);
	    }
  	}
}

void QuienEsQuien::escribir_arbol_completo() const{
	string pre = "";
	escribir_esquema_arbol(cout,this->arbol,this->arbol.root(),pre);
}

void QuienEsQuien::eliminar_nodos_redundantes_recursivo(bintree<Pregunta>::node nodo){
	while ((nodo.left().null() && !nodo.right().null()) ||
	(!nodo.left().null() && nodo.right().null())) {
		bintree<Pregunta> aux;
		if(nodo == arbol.root()) {
			if(nodo.right().null())
				arbol.prune_left(nodo, aux);
			else
				arbol.prune_right(nodo,aux);

			arbol = aux;
			nodo = arbol.root();

		} else {
			bintree<Pregunta>::node padre = nodo.parent();

			if (nodo.left().null())
				arbol.prune_right(nodo, aux);
			else
				arbol.prune_left(nodo, aux);

			if (padre.left() == nodo) {
				arbol.insert_left(padre, aux);
				nodo = padre.left();
			} else {
				arbol.insert_right(padre, aux);
				nodo = padre.right();
			}
		}
	}

	if (!nodo.left().null() && !nodo.right().null()) {
		eliminar_nodos_redundantes_recursivo(nodo.left());
		eliminar_nodos_redundantes_recursivo(nodo.right());
	}
}

void QuienEsQuien::eliminar_nodos_redundantes(){
	eliminar_nodos_redundantes_recursivo(arbol.root());
}

void QuienEsQuien::profundidad(int depth, bintree<Pregunta>::node nodo,vector<int> & v ){
		if( !nodo.left().null() ){
			profundidad(depth + 1, nodo.left(),v);
		} if( !nodo.right().null() ){
			profundidad(depth + 1, nodo.right(),v);
		}
		if( (*nodo).es_personaje() ){
			v.push_back(depth);
		}
}

float QuienEsQuien::profundidad_promedio_hojas(){

  vector<int> profundidades;
	 profundidad(0, arbol.root(), profundidades);
	 float suma = 0;

	 for(vector<int>::iterator it=profundidades.begin(); it != profundidades.end(); ++it)
		 suma += *it;

	float media = suma/profundidades.size();

	return media;
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max).
**/

int generaEntero(int min, int max){
    int tam= max -min;
    return ((rand()%tam)+min);
}

void QuienEsQuien::tablero_aleatorio(int numero_de_personajes){
	srand(0);

	this->limpiar();

	float log_2_numero_de_personajes = log(numero_de_personajes)/log(2);

	int numero_de_atributos = ceil(log_2_numero_de_personajes);

	cout << "Petición para generar "<< numero_de_personajes<<" personajes ";
	cout << "con "<<numero_de_atributos<< " atributos"<<endl;
	cout << "Paso 1: generar "<< pow(2,numero_de_atributos) << " personajes"<<endl;

	//Fase 1: completar el tablero con todos los personajes posibles
	//Completo el tablero y los nombres de personajes a la vez,
	for(int indice_personaje=0;indice_personaje< pow(2,numero_de_atributos);indice_personaje++){
		vector<bool> atributos_personaje = convertir_a_vector_bool(indice_personaje,numero_de_atributos);
		string nombre_personaje = "Personaje_"+to_string(indice_personaje);

		this->personajes.push_back(nombre_personaje);
		this->tablero.push_back(atributos_personaje);
	}

	// Completo los nombres de los atributos.
	for(int indice_atributo=0;indice_atributo<numero_de_atributos;indice_atributo++){
		string nombre_atributo = "Atributo_"+to_string(indice_atributo);
		this->atributos.push_back(nombre_atributo);
	}

	cout << "Paso 2: eliminar "<< (pow(2,numero_de_atributos)-numero_de_personajes) << " personajes"<<endl;
	//Fase 2. Borrar personajes aleatoriamente hasta que quedan solo los que hemos pedido.
	while(personajes.size()>numero_de_personajes){
		int personaje_a_eliminar = generaEntero(0,personajes.size());

		personajes.erase(personajes.begin()+personaje_a_eliminar);
		tablero.erase(tablero.begin()+personaje_a_eliminar);
	}
}

stack<pair<string,string>> QuienEsQuien::preguntas_formuladas(bintree<Pregunta>::node jugada){
	stack<pair<string,string>> pila;
	while(jugada != arbol.root()) {
		bintree<Pregunta>::node aux(jugada);
		jugada = jugada.parent();
		if(jugada.left() == aux)
			pila.push(pair<string,string>((*jugada).obtener_pregunta(),"Sí"));
		else
			pila.push(pair<string,string>((*jugada).obtener_pregunta(),"No"));
		}

		return pila;
}

	void QuienEsQuien::aniade_personaje(string nombre, vector<bool> caracteristicas) {
		bintree<Pregunta>::node nodo = arbol.root();
		int pos = distance(atributos.begin(), find(atributos.begin(), atributos.end(), (*nodo).obtener_pregunta()));
		vector<string> atributosUsados;

		//Buscamos en que nodo habria que insertarlo, que puede ser con otro personaje
		//o en una rama en la que no haya ningun personaje si el arbol tiene redundancias.
		while( ((*nodo).es_pregunta()) && !(nodo.right().null() && !caracteristicas[pos]) && !(nodo.left().null() && caracteristicas[pos])) {
			(*nodo) = Pregunta((*nodo).obtener_pregunta(), (*nodo).obtener_num_personajes()+1);
			atributosUsados.push_back((*nodo).obtener_pregunta());

			if(caracteristicas[pos] && !nodo.left().null() )
					nodo = nodo.left();
			else if( !caracteristicas[pos] && !nodo.right().null())
				nodo = nodo.right();

			if( (*nodo).es_pregunta() )
				pos = distance(atributos.begin(), find(atributos.begin(), atributos.end(), (*nodo).obtener_pregunta()));
		}


		vector<bool> atr;
		vector<bool> atr_nuevoP;
		vector<string> nuevosPersonajes;
		vector<string> nuevosAtributos;

		if( (*nodo).es_personaje() ){
			//Hacemos un nuevo tablero con los dos personajes y los atributos que aun no se han usado:
			nuevosPersonajes.push_back((*nodo).obtener_personaje());
			int p = distance(personajes.begin(), find(personajes.begin(), personajes.end(), (*nodo).obtener_personaje() ));
			nuevosPersonajes.push_back(nombre);

			for(auto it = atributos.begin(); it != atributos.end(); ++it){
				if( find(atributosUsados.begin(), atributosUsados.end(),*it) == atributosUsados.end() ){
					nuevosAtributos.push_back(*it);
					int i = distance(atributos.begin(), find(atributos.begin(), atributos.end(), *it));
					atr.push_back(tablero[p][i]);
					atr_nuevoP.push_back(caracteristicas[i]);
				}
			}

			vector<vector<bool>> nuevoTablero;
			nuevoTablero.push_back(atr);
			nuevoTablero.push_back(atr_nuevoP);

			Pregunta preg( opcionPregunta(nuevosAtributos, nuevoTablero), 2);
			bintree<Pregunta> subarbol(preg);

			int j = distance(nuevosAtributos.begin(), find(nuevosAtributos.begin(), nuevosAtributos.end(),
			 opcionPregunta(nuevosAtributos, nuevoTablero)));

			 Pregunta personaje_antiguo( (*nodo).obtener_personaje(), 1 );
			 Pregunta personaje_nuevo(nombre, 1);
			 if( atr[j] ){
				 	subarbol.insert_left(subarbol.root(), personaje_antiguo);
					subarbol.insert_right(subarbol.root(), personaje_nuevo);
			 } else {
				 subarbol.insert_right(subarbol.root(), personaje_antiguo);
				 subarbol.insert_left(subarbol.root(), personaje_nuevo);
			 }

			 	bintree<Pregunta>::node padre = nodo.parent();

				if(padre.left() == nodo )
					arbol.insert_left(padre, subarbol);
				else
					arbol.insert_right(padre, subarbol);
				}

			if( nodo.right().null() && !caracteristicas[pos] ) {
				Pregunta personaje_nuevo(nombre, 1);
				arbol.insert_right(nodo, personaje_nuevo);
			}

			if( nodo.left().null() && caracteristicas[pos] ){
				Pregunta personaje_nuevo(nombre, 1);
				arbol.insert_left(nodo, personaje_nuevo);
			}
			personajes.push_back(nombre);
			tablero.push_back(caracteristicas);
		}

void QuienEsQuien::elimina_personaje(string nombre){

	bintree<Pregunta>::node nodo = arbol.root();
	
	if( informacion_jugada(nodo).count(nombre) ){

		while( (*nodo).es_pregunta() ){
			if( informacion_jugada(nodo.left()).count(nombre) )
				nodo = nodo.left();
			else
				nodo = nodo.right();
		}

		bintree<Pregunta>::node aux = nodo.parent();
		bintree<Pregunta> poda;

		if(aux.left() == nodo)
			arbol.prune_right(aux, poda);
	 	else
			arbol.prune_left(aux,poda);

		if(aux.parent().left() == aux)
			arbol.insert_left(aux.parent(),poda);
		else
			arbol.insert_right(aux.parent(),poda);
		
		personajes.erase( find(personajes.begin(), personajes.end(), nombre) );
	}
	
}

int QuienEsQuien::modo_juego() {
	return MODO_MEJORADO;
}

//Pre: i = 0 ó i = 1
void QuienEsQuien::set_modo_juego(int i) {
	MODO_MEJORADO= i;
}


int QuienEsQuien::numero_de_atributos() {
	return tablero[0].size();
}
