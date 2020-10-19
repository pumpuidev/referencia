param($file)
$filet=Get-Content $file
$d=$false
foreach ($szo in $filet)
{
    if ($szo -match "^k[a-z]{1,7}l$")
    {
        $d=$true
        echo $szo
    }
}
$d
if (!$d){
    echo "NOT_FOUND"
}