$szamok=@(Get-random -InputObject (1..90) -Count 5)
$talalt=0
write-host $szamok
for ($i=0; $i -lt 5;$i++){
    $beolvas=Read-Host
    if ($szamok.Contains($beolvas)){
        $talalt++
    }
} 

Write-Host $talalt "szam talalt"
write-host $szamok
