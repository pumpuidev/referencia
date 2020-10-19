PARAM([int]$n)

for ($i=1;$i -le $n;$i++)
{
    for ($j=1;$j -le $n;$j++){
       if (($i -eq 1) -or ($i -eq $n) -or
                    ($j -eq 1) -or (-$ -eq $n))
            {
                $betű="A"
            }
            else {$betű="B"}
             write-host $betű -NoNewline
 }
    write-host
 }
