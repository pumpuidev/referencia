#!/bin/bash

n=$1
echo -n "Sn"
echo -n "!-1"
fakt=1
i=2
while [$i -le $n-1]; do
	echo -n "*$i"
	fakt= expr $fakt \* $i
	#i= expr $i +1
	((i++))
done
echo "=$fakt"