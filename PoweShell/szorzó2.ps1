for ($i=1;$i -le 10;$i++)
{
    for ($j=1;$j -le 10;$j++){
        Write-Host ($i*$j)"`t"  -NoNewline
        #Write-Host " " -NoNewline
    }
    Write-Host 
}