#!/bin/bash
szam=0
echo $szam
szam2=oszt
echo "oszt"
if [ $szam -lt 10 ]; 
then
	echo "osztas"
else
	if [ $szam -ge 18]; 
	then
		echo "oszthato"
	else
		echo "nem oszthato"
	fi
fi