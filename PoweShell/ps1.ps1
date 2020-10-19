function test
{
param ($name)
begin {
if($name) {
if($name -is [string]) {$name | test}
else {$name.name | test}
}
}
process {
if($_) {
if($_ -is [string]) {"Nev: $_, nev hossza: $($_.length)" }
else {"Nev: $($_.name), nev hossza: $($_.name.length)" }
}
}
}