#!/bin/bash

echo "Adj meg 3 szamot:"
read A
read B
read C

oldalak=($A $B $C)
rendezett=($(printf '%s\n' "${oldalak[@]}"|sort))

A=${rendezett[0]}
B=${rendezett[1]}
C=${rendezett[2]}

if [ $((A*A+B*B)) -ne $((C*C)) ] ; then
        echo "Nem derekszogu haromszog!"
else
        echo "Derekszogu haromszog!"
fi