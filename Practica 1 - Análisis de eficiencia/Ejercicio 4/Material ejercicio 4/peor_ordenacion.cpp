#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void ordenar(int *v, int n) {
	for (int i=0; i<n-1; i++)
	for (int j=0; j<n-i-1; j++)
	if (v[j]>v[j+1]) {
	int aux = v[j];
	v[j] = v[j+1];
	v[j+1] = aux;
	}
}

void sintaxis() {
cerr << "Sintaxis:" << endl;
cerr << " TAM: Tamaño del vector (>0)" << endl;
cerr << " VMAX: Valor máximo (>0)" << endl;
cerr << "Genera un vector de TAM números aleatorios en [0,VMAX[" << endl;
exit(EXIT_FAILURE);
}
int main(int argc, char * argv[]) {
if (argc!=2)
// Lectura de parámetros
sintaxis();
int tam=atoi(argv[1]);
// Generación del vector aleatorio
int *v=new int[tam];
// Reserva de memoria

// Inicialización generador números pseudoaleatorios
for (int i=0; i<tam; i++) // Recorrer vector
v[tam-i-1] = i;
// Generar aleatorio [0,vmax[
clock_t tini;
tini=clock();
// Anotamos el tiempo de inicio

ordenar(v,tam); // de esta forma forzamos el peor caso
clock_t tfin;
tfin=clock();
// Anotamos el tiempo de finalización
// Mostramos resultados (Tamaño del vector y tiempo de ejecución en seg.)
cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;
delete [] v;
}
