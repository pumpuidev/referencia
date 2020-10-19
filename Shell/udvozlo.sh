#!/bin/bash
ora=`date +%H`
#echo $ora
if [ $ora -lt 10 ]; then
	echo "Jo reggelt!"
else
	if [ $ora -ge 18]; then
		echo "Jo estet!"
	else
		echo "Jo napot!"
	fi
fi