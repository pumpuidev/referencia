# A k�vetkezo program a megadott n�v alapj�n k�sz�nti a felhaszn�l�t
# A Winforms bet�lt�se
[reflection.assembly]::LoadWithPartialName( "System.Windows.Forms")

# Form k�sz�t�se
$f = New-Object Windows.Forms.Form
$f.text = "Greetings Form"
$f.Size = New-Object Drawing.Point 200,150

# C�mke k�sz�t�se
$l = New-Object Windows.Forms.Label
$l.Location = New-Object Drawing.Point 50,30
$l.Size = New-Object Drawing.Point 100,15
$l.text = "Add meg a neved!"

# Beviteli mezo k�sz�t�se
$t = New-Object Windows.Forms.TextBox
$t.Location = New-Object Drawing.Point 50,60
$t.Size = New-Object Drawing.Point 100,30

# Gomb k�sz�t�se
$b = New-Object Windows.Forms.Button
$b.text = "Hello"
$b.Location = New-Object Drawing.Point 60,90

# Esem�nykezelo a gombhoz
$b.add_click({

$l.Text = "�dv " + $t.text + "!"

})

# A vez�rlok hozz�ad�sa a Formhoz
$f.controls.add($b)
$f.controls.add($l)
$f.controls.add($t)

# A Form megjelen�t�se
$f.ShowDialog()
