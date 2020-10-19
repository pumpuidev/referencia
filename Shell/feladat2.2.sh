#!/usr/bin/env bash

N=$1
M=$2

for X in $(seq $N $M) ; do
        if [ $((X%2)) -ne 0 ] ; then
                echo $X
        fi
done