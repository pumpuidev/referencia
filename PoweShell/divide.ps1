#Hallgattasuk el a hiba�zeneteket
$local:ErrorActionPreference = "SilentlyContinue"

#A param�ter�l megadott k�t sz�mot t�roljuk el
#A powershell gyeng�n t��pusos nyelv de az al�bb l�that� m�don t�pust k�nyszer�thet�nk a v�ltoz�ra
[Int32] $a = $args[0]
[Int32] $b = $args[1]
[Int32] $result = $a / $b
[Int32] $modulus = $a % $b

#A t�pusk�nyszer�t�s miatt a k�vetkezo sor �jabb k�nyszer�t�s n�lk�l nem muk�dne
[String] $a + "/" + [String] $b + " = " + [String] $result  + " marad�k a(z) " + [String] $modulus

#A null�val oszt�s kiv�telt dobna ez�rt most elkapjuk
trap [System.DivideByZeroException] {
	"Null�val oszt�s"
	#A program meg�ll�t�sa
	exit
}