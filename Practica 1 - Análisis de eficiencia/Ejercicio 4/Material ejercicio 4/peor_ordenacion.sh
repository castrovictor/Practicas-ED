#!/bin/bash

g++ -g peor_ordenacion.cpp -o peorordenacion
inicio=100
fin=30000
incremento=500
ejecutable="peorordenacion"
salida="tiempos_peor_ordenacion.dat"

i=$inicio
echo > $salida
while [ $i -lt $fin ]
do
	echo "Ejecución tam = " $i
	echo `./$ejecutable $i` >> $salida
	i=$[ $i + $incremento ]
done 
