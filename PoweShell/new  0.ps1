#!/bin/sh

help() {
	echo egy parameterrel dolgozik, es az egy letezo fajl
}
f="eredmeny.$$"
if [ $# -eq 1 ]
then
 if [ -f $1 ]
 then
   #ertekes
   #cat $1 | while read szo
			while read szo 
			do 
				echo $szo >> $f 
	#		 done
			done < $1
   
   sort $f 
   rm $f 
 else
   help 
 fi
else
  help
fi

