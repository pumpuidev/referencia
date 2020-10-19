$n=$args[0]

if ($n % 2 -eq 0){
    write-output 'NOT_ODD'
    exit
}
for ($i = 0; $i -lt $n ; $i++){
    for ($j =0; $j -lt $n; $j++){
        if ($i -eq $n-1 -or $j -eq $n-1 -or $i -eq 0 -or $j -eq 0){
        Write-host '*' -NoNewline
        }
        else {
        write-host '@' -NoNewline
        }
    } 
    write-host 
} 