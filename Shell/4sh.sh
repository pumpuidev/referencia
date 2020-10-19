#!/bin/bash
if [$# -eq 0]; then
	echo "Kiírja az első par..."
else	
	file=$1
	if [ ! -f $file ]; then
		echo "Hiba! Nem letezik..."
	else
		if [];then
			azon=$2
		else
			echo -n "Milyen kodot keres... "
			

		grep "$azon: " $file
	fi
fi