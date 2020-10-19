# A következo program a megadott név alapján köszönti a felhasználót
# A Winforms betöltése
[reflection.assembly]::LoadWithPartialName( "System.Windows.Forms")

# Form készítése
$f = New-Object Windows.Forms.Form
$f.text = "Greetings Form"
$f.Size = New-Object Drawing.Point 200,150

# Címke készítése
$l = New-Object Windows.Forms.Label
$l.Location = New-Object Drawing.Point 50,30
$l.Size = New-Object Drawing.Point 100,15
$l.text = "Add meg a neved!"

# Beviteli mezo készítése
$t = New-Object Windows.Forms.TextBox
$t.Location = New-Object Drawing.Point 50,60
$t.Size = New-Object Drawing.Point 100,30

# Gomb készítése
$b = New-Object Windows.Forms.Button
$b.text = "Hello"
$b.Location = New-Object Drawing.Point 60,90

# Eseménykezelo a gombhoz
$b.add_click({

$l.Text = "Üdv " + $t.text + "!"

})

# A vezérlok hozzáadása a Formhoz
$f.controls.add($b)
$f.controls.add($l)
$f.controls.add($t)

# A Form megjelenítése
$f.ShowDialog()
