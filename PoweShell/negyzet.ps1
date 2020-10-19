$n=$args[0]

for ($i = 1; $i -lt $n+1; $i++){
    $negyzet= $i * $i
    if ($i -gt 1){
        write-host ",$negyzet" -NoNewline
    }
    else{
        write-host "$negyzet" -NoNewline
    }
} 
write-host 