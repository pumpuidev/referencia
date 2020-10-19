[int]$osszeg=1
for ($i=0;$i -lt $args.Length;$i++){
    [int]$osszeg*=$args[$i]
}
write-host $osszeg
