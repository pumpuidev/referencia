#Paraméterellenorzés
if ($args.length -eq 0){
	"Túl kevés paraméter!!! Kérlek adj meg egy pozitív számsorozatot!"
}
else{
	#Maximumkeresés a paraméterek között
	foreach ($curr in $args){
		#Csak a számokat szabad nézni ezért típust egyeztetünk
		if ($curr.getType().name -eq "Int32" -and $curr -gt $max){ $max = $curr}
	}
	#Eredmény kiíratása, ha nem volt szám a max értéke üres
	"A maximum érték: " + $max
}