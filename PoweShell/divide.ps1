#Hallgattasuk el a hibaüzeneteket
$local:ErrorActionPreference = "SilentlyContinue"

#A paraméterül megadott két számot tároljuk el
#A powershell gyengén tíípusos nyelv de az alább látható módon típust kényszeríthetünk a változóra
[Int32] $a = $args[0]
[Int32] $b = $args[1]
[Int32] $result = $a / $b
[Int32] $modulus = $a % $b

#A típuskényszerítés miatt a következo sor újabb kényszerítés nélkül nem muködne
[String] $a + "/" + [String] $b + " = " + [String] $result  + " maradék a(z) " + [String] $modulus

#A nullával osztás kivételt dobna ezért most elkapjuk
trap [System.DivideByZeroException] {
	"Nullával osztás"
	#A program megállítása
	exit
}