#param([int]$szám)
#$szám=$args[0]
$szám=Read-Host "Meddig?"
$fakt=1
for ($i=1;$i -le $szám;$i++){
    $fakt*=$i
}
Write-Host $fakt