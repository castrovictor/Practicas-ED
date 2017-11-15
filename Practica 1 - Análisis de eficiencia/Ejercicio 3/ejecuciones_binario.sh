#!/bin/bash

g++ -g ejercicio_desc.cpp -o ej3
inicio=100
fin=30000
incremento=500
ejecutable="ej3"
salida="tiempos_binario_medio.dat"

i=$inicio
echo > $salida
while [ $i -lt $fin ]
do
	echo "Ejecución tam = " $i
	echo `./$ejecutable $i` >> $salida
	i=$[ $i + $incremento ]
done 
