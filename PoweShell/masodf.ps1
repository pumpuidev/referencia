[int]$a=read-host "a"
[int]$b=read-host "b"
[int]$c=read-host "c"
if ($a -eq 0){
    if ($b -eq 0) {
        if ($c -eq 0){write-host azonossag}
        else {write-host ellentmondás}
    }
    else {
        write-host -$c/$b
    }
}else{
    $d=$b*$b-4*$a*$c 
    if ($d -lt 0) {Write-Host komplex}
    else
    {
        if ($d -eq 0) {write-host (-$b/2/$a)}
        else {
            $d=[System.Math]::sqrt($d)
            $x1=(-$b-$d)/(2*$a)
            $x2=(-$b+$d)/(2*$a)
            write-host "$x1 , $x2"
        }
    }
}