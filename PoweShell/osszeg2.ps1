#param([int]$also,[int]$felso)
if ($args.length -ne 2){
    Write-Host "2 parameter!"
    exit
}
$also=$args[0]
$felso=$args[1]

if ($also -le $felso){

    $osszeg=0
    for ($i=$also;$i -le $felso;$i++){
    $osszeg+=$i
    }
    write-host $osszeg
}else {
    write-host "hiba"
}