#Param�terellenorz�s
if ($args.length -eq 0){
	"T�l kev�s param�ter!!! K�rlek adj meg egy pozit�v sz�msorozatot!"
}
else{
	#Maximumkeres�s a param�terek k�z�tt
	foreach ($curr in $args){
		#Csak a sz�mokat szabad n�zni ez�rt t�pust egyeztet�nk
		if ($curr.getType().name -eq "Int32" -and $curr -gt $max){ $max = $curr}
	}
	#Eredm�ny ki�rat�sa, ha nem volt sz�m a max �rt�ke �res
	"A maximum �rt�k: " + $max
}