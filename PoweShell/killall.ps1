#A paraméterben megadott programok eroszakos leállítása
foreach($program in $args){
	#Minden megadott programnévre nézzük meg a futó folyamatok nevét
	$processes = Get-Process $program
	$name = $processes.ProcessName
	$killed = 0
	#Öljünk meg minden futó folyamatot az adott programból
	foreach($instance in $processes){
		$instance.Kill()
		$killed++
	}
	#Írjuk ki az eredményt
	"I could slay " + $killed + " instance of " + $program
}