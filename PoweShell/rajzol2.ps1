$n=$args[0]

if ($n % 2 -eq 0){
    write-output 'NOT_ODD'
    exit
}
for ($i = 0; $i -lt $n ; $i++){
    for ($j =0; $j -lt $n; $j++){
        if ($i -eq ($n-1)/2 -and $j -eq ($n-1)/2){
        Write-host '@' -NoNewline
        }
        else {
        write-host '*' -NoNewline
        }
    } 
    write-host 
} 