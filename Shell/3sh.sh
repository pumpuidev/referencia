#!/bin/bash
echo -n "Hany sor ilyen? "
read n
	
for ((i=1;i<=n;i++));do
	for((j=1;j<=5;j++));do
		echo -n $i
	done
	echo
done