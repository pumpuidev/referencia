#!/bin/bash

i='file'

if [ $# -ne 1 -o ! -f "$1" ] ; then
	echo "nincs ilyen fajlnev"
	exit
fi
