#A param�ter�l megadott k�t f�jl megnyit�sa a .NET framework seg�ts�g�vel
$f1 = [System.IO.File]::OpenText($args[0])
$f2 = [System.IO.File]::OpenText($args[1])

#Fel�l�rjuk a result.txt-t redirection-nel
"Merged content:" > result.txt

#F�s�lj�k �ssze a k�t f�jlt soronk�nt vegyesen
#Az EndOfStream igaz lesz ha a filele�r� a file v�g�re �rt
while (! $f1.EndOfStream -or  ! $f2.EndOfStream) {
	#Sor olvas�sa �s �tir�ny�t�sa a result.txt v�g�r
	$f1.ReadLine() >> result.txt
	$f2.ReadLine() >> result.txt
}

#Ha hosszabb az egyik f�jl a fennmarad� r�szt be kell �rni a f�jlba
if($f1.EndOfStream){
	while (! $f2.EndOfStream){
		$f2.ReadLine() >> result.txt
	}
}
if($f2.EndOfStream){
	while (! $f1.EndOfStream){
		$f1.ReadLine() >> result.txt
	}
}

#F�jlok lez�r�sa
$f1.Close()
$f2.Close()
