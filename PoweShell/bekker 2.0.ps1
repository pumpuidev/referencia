$file = Get-Content $args[0]
for ($i = 0; $i -le 100; $i++) 
{ 
  $tomb += @(0) 
}
[string]$sor=""
$j=0;
foreach ($sor in $file){
	$sor=$sor.replace(",","")
	$sor=$sor.replace(".","")
	$sor=$sor.replace("!","")
	$sor=$sor.replace("?","")
	$sor=$sor.replace("-","")
	$mod = $sor -split "\s+";
		for ( $i=0; $i -le $mod.length; $i++){
			if ($mod[$i].length -gt $j){
				$j=$mod[$i].length
			}
			$tomb[$mod[$i].length-1]+=1
		}
}
$k=0
for($k=0; $k -le $j-1; $k++){
	$kk=$k+1
	if ($tomb[$k] -ne 0){
		Write-Host -NoNewline $kk " karakteres szavak: " $tomb[$k];
		Write-Output "";
		}
}