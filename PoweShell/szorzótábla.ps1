for ($i=1;$i -le 10;$i++)
{
    for ($j=1;$j -le 10;$j++){
        $ert=($i*$j)
        $e=" $ert"
        Write-Host $e.substring($e.length-3,3) "`t"  -NoNewline
        #Write-Host " " -NoNewline
    }
    Write-Host 
}