#!/bin/bash

g++ -g ordenacion.cpp -o ordenacion
inicio=100
fin=30000
incremento=500
ejecutable="ordenacion"
salida="tiempos_ordenacion.dat"

i=$inicio
echo > $salida
while [ $i -lt $fin ]
do
	echo "Ejecución tam = " $i
	echo `./$ejecutable $i` >> $salida
	i=$[ $i + $incremento ]
done 
