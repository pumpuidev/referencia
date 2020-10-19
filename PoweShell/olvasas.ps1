$szo=read-host "Kerek egy szot!"
while ("$szo" -ne "vége"){
    Write-output $szo >> eredm.txt
    $szo=Read-Host "Kerek egy szot"
}
Get-Content eredm.txt | Sort-Object