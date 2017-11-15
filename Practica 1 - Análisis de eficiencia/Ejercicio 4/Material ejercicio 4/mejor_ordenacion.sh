#!/bin/bash

g++ -g mejor_caso_ordenacion.cpp -o mejorordenacion
inicio=100
fin=30000
incremento=500
ejecutable="mejorordenacion"
salida="tiempos_mejor_ordenacion.dat"

i=$inicio
echo > $salida
while [ $i -lt $fin ]
do
	echo "Ejecución tam = " $i
	echo `./$ejecutable $i` >> $salida
	i=$[ $i + $incremento ]
done 
