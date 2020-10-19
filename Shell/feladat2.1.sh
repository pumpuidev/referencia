#!/bin/bash

n=$1
m=$2

for ((i=0; $i < $n;i++)) ; do
	for ((j=0; $j < $m;j++)) ; do
	echo  -n "A"
	done
	echo
done
