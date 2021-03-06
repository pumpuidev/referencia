if (($args.count -le 0) -or (-not (test-path $args[0]))) {
  write-output "Nincs fajl parameter vagy a fajl nem letezik!"
  exit
}

$length = @{}

get-content $args[0] | foreach {
    $line = ($_ -replace '\s+', ' ').trim()

    if ($line.length -gt 0) {
        $line.split(" ")|foreach{
             $length[$_.length]++
        }
    }
}

$length.GetEnumerator()|sort-object Name