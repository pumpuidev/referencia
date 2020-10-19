#A param�terben megadott programok eroszakos le�ll�t�sa
foreach($program in $args){
	#Minden megadott programn�vre n�zz�k meg a fut� folyamatok nev�t
	$processes = Get-Process $program
	$name = $processes.ProcessName
	$killed = 0
	#�lj�nk meg minden fut� folyamatot az adott programb�l
	foreach($instance in $processes){
		$instance.Kill()
		$killed++
	}
	#�rjuk ki az eredm�nyt
	"I could slay " + $killed + " instance of " + $program
}