param($file,$div)
if ($file -eq $null -or !(Test-Path $file)){
    echo "FILE_NOT_EXISTS"
    exit
}
elseif ($div -eq 0 -or $div -eq $null)
{
    echo "BAD_DIVIDER"
    exit
}
$filet=Get-Content $file
$divt=@()
foreach ($row in $filet)
{
    if ($row % $div -eq 0)
    {
        $divt+=$row
    }
}
$nk=0
if ($divt.Length -ne 0)
{ 
    foreach($d in $divt)
    {
        $nk+=[math]::Pow($d,2)
    }
    $nk=[System.Math]::Sqrt($nk/$divt.Length)
}
echo $nk