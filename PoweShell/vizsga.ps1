$file=$args[0]
$neptun=$args[1]
$talalt=0
if (-not (Test-Path $file)){
    write-host FILE_NOT_EXIST
    exit
}
if ((Get-Content $file) -eq $null ){
    write-host EMPTY_FILE
    exit
}
get-content $file |foreach{
    $mezok=$_.ToString().Split(';')

    if ($mezok[1] -eq $neptun){
    write-host $mezok[2]
    $talalt=1
    }   
   }
if ($talalt -eq 0){
    write-host NOT_FOUND
}