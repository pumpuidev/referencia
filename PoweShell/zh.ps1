$szamok=@(1,2,3)

for ($i=0 ; $i -lt 3 ; $i++) {
    $szamok[$i]=read-host
}

$rendezett=$szamok|Sort-Object

[string]$rendezett

#1. feladat: 3 sz�m sorba rendez�se (ez, csak egyjegy�vel m�kszik)
#2. feladat: lnko
#3. feladat: random sz�veg x-szel kezd�d� sorban sz�molja meg a karaktereket
#4. feladat: A-b�l der�ksz�g� h�romsz�g