$szamok=@(1,2,3)

for ($i=0 ; $i -lt 3 ; $i++) {
    $szamok[$i]=read-host
}

$rendezett=$szamok|Sort-Object

[string]$rendezett

#1. feladat: 3 szám sorba rendezése (ez, csak egyjegyûvel mûkszik)
#2. feladat: lnko
#3. feladat: random szöveg x-szel kezdõdõ sorban számolja meg a karaktereket
#4. feladat: A-ból derékszögû háromszög