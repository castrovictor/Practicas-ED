#!/bin/bash

g++ -g burbuja.cpp -o burbuj
inicio=100
fin=30000
incremento=500
ejecutable="burbuja"
salida="tiempos_burbuja.dat"

i=$inicio
echo > $salida
while [ $i -lt $fin ]
do
	echo "Ejecución tam = " $i
	echo `./$ejecutable $i` >> $salida
	i=$[ $i + $incremento ]
done 
