param($kapcs)
write-host $kapcs
switch ($kapcs){
    -l {Get-Content "telefon.txt" }
    -d {
    $nev=read-host "neve:"
    $tel=get-content "telefon.txt"
    foreach ($sor in $tel){ 
        if ($sor -match $nev){}
        else {Write-Output $sor >> temp.txt}
    }
    Remove-Item telefon.txxt
    Rename-Item temp.txt telefon.txt
    }
   "-a"{
    $nev=Read-Host "neve: "
     $tel=Read-Host "tel: "
     write-output "$nev ; $tel" >> telefon.txt
   }
}