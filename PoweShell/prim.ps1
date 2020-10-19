param([int]$sz)
function prime($sz){
    #param($sz)
    $i=2
    while (($sz -gt $i) -and (($sz % $i) -ne 0)){
        $i++
    }
    return $sz -le $i
}
#$sz=read-host "Kerem a szamot"
if (prime( $sz)) {
    write-host prim
}else {
    write-host nem
}