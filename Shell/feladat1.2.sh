#!/bin/bash

n=$1

for i in $(seq $n) ; do
	if  [ $((n%i)) -eq 0 ] ; then
		echo $i
	fi
done
