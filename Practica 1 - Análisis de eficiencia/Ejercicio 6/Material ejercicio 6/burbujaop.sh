#!/bin/bash

g++ -O3 burbujaop.cpp -o burbuja_optimizado
inicio=100
fin=30000
incremento=500
ejecutable="burbuja_optimizado"
salida="tiempos_burbuja_optimizado.dat"

i=$inicio
echo > $salida
while [ $i -lt $fin ]
do
	echo "Ejecución tam = " $i
	echo `./$ejecutable $i` >> $salida
	i=$[ $i + $incremento ]
done 
