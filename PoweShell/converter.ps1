param($from,$to,$file)
$hext=@{10='A';11='B';12='C';13='D';14='E';15='F'; }

function toHex()
{
    param($act)
    if ($act -ge 10)
    {
        foreach ($h in $hext.Keys)
        {
            if ($h -eq $act)
            {
                $hexa=$hext[$h]
            }
        }                
    }
    else
    {
        $hexa=$act.ToString()
    }
    return $hexa
}

if ($from -eq 2)
{
    if ($to -eq 8)
    {
        $filet=Get-Content $file
        foreach ($num in $filet)
        {
            $oct=""
            $j=0
            $act=0
            for($i=$num.Length-1; $i -ge 0;$i--)
            {
                if ($j -eq 3){
                    $oct=$act.ToString()+$oct
                    $j=0
                    $act=0
                }
                $act+=([int]$num[$i]-48)*[math]::Pow(2,$j)
                $j++
            }
            $oct=$act.ToString()+$oct
            echo $oct
        }
    }
    elseif($to -eq 16)
    {
        $filet=Get-Content $file
        foreach ($num in $filet)
        {
            $hex=""
            $j=0
            $act=0
            for($i=$num.Length-1; $i -ge 0;$i--)
            {
                if ($j -eq 4){
                
                    $t=toHex($act)
                    $hex=$t.toString()+$hex
                    $j=0
                    $act=0
                }
                $act+=([int]$num[$i]-48)*[math]::Pow(2,$j)
                $j++
            }
            $t=toHex($act)
            $hex=$t.toString()+$hex
            echo $hex
        }
    }
}
elseif ($from -eq 8)
{
    if ($to -eq 2)
    {
        $filet=Get-Content $file
        foreach($num in $filet)
        {
            $bin=""
            for($i=0;$i -lt $num.Length;$i++)
            {
                $hi=[int]$num[$i]-48
                for($j=2;$j -ge 0;$j--)
                {
                    if ([math]::Truncate($hi/([math]::Pow(2,$j))) -eq 1)
                    {
                        $hi-=[math]::Pow(2,$j)
                        $bin+="1"
                    }
                    else
                    {
                        $bin+="0"
                    }
                }
            }
            echo $bin
        }
    }
}
elseif ($from -eq 16)
{
    if ($to -eq 2)
    {
        $filet=Get-Content $file
        foreach($num in $filet)
        {
            $bin=""
            for($i=0;$i -lt $num.Length;$i++)
            {
                if ([int]$num[$i] -ge 65)
                {
                    foreach($n in $hext.Keys)
                    {
                        if ($hext[$n] -eq $num[$i])
                        {
                            $hi=$n
                        }
                    }
                }
                else
                {
                    $hi=[int]$num[$i]-48
                }
                for($j=3;$j -ge 0;$j--)
                {
                    if ([math]::Truncate($hi/([math]::Pow(2,$j))) -eq 1)
                    {
                        $hi-=[math]::Pow(2,$j)
                        $bin+="1"
                    }
                    else
                    {
                        $bin+="0"
                    }
                }
            }
            echo $bin
        }
    }
}