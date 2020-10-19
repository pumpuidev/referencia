#A paraméterül megadott két fájl megnyitása a .NET framework segítségével
$f1 = [System.IO.File]::OpenText($args[0])
$f2 = [System.IO.File]::OpenText($args[1])

#Felülírjuk a result.txt-t redirection-nel
"Merged content:" > result.txt

#Fésüljök össze a két fájlt soronként vegyesen
#Az EndOfStream igaz lesz ha a fileleíró a file végére ért
while (! $f1.EndOfStream -or  ! $f2.EndOfStream) {
	#Sor olvasása és átirányítása a result.txt végér
	$f1.ReadLine() >> result.txt
	$f2.ReadLine() >> result.txt
}

#Ha hosszabb az egyik fájl a fennmaradó részt be kell írni a fájlba
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

#Fájlok lezárása
$f1.Close()
$f2.Close()
