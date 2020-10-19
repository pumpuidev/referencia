param([int]$szám)
$fakt=1
for ($i=1;$i -le $szám;$i++){
    $fakt*=$i
}
Write-Host $fakt