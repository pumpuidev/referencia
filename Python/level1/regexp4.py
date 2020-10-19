#! /usr/bin/env python
# -*- coding: iso-8859-2 -*-

import re

# Regularis kifejezesek

'[]' # karakterek halmazát jelöli

m = re.match("[aAbB]*", "AbbaCBcfde")
print m.group()
# Abba

print re.findall("[0-9+\-]{7,15}", "Kiss Pal 06-1-123-4567, Nagy Geza 06-10-234-345, Toth Bela +36-30-345-3211")
# ['06-1-123-4567', '06-10-234-345', '+36-30-345-3211']

print re.findall("[^0-9+\-,]+", "Kiss Pal 06-1-123-4567, Nagy Geza 06-10-234-345, Toth Bela +36-30-345-3211")
# ['Kiss Pal ', ' Nagy Geza ', ' Toth Bela ']

print re.findall("[a-zA-Z ]+", "Kiss Pal 06-1-123-4567, Nagy Geza 06-10-234-345, Toth Bela +36-30-345-3211")
# ['Kiss Pal ', ' Nagy Geza ', ' Toth Bela ']


'\d' # digitális karakterek [0-9]

'\D' # nem digitális karakterek [^0-9]

'\w' # alfanumerikus karakterek [a-zA-Z0-9_]

'\W' # nem alfanumerikus karaketerek [^a-zA-Z0-9_]

'\s' # whitespace karakterek 

'\S' # nem whitespace karakterek 

print re.findall("[\d+\-]{7,15}", "Kiss Pal 06-1-123-4567, Nagy Geza 06-10-234-345, Toth Bela +36-30-345-3211")
# ['06-1-123-4567', '06-10-234-345', '+36-30-345-3211']


'|' # választás A|B -- A vagy B, balról jobbra értékelődik ki, ha A illeszkedett, B-t nem keresi

m = re.match("\d+|[0-9\-]+", "06-1-123-4567")
print m.group()
# 06

m = re.match("[0-9\-]+|\d+", "06-1-123-4567")
print m.group()
# 06-1-123-4567


'()' # csoportosítás

m = re.match("(\d+)|([0-9\-]+)", "06-1-123-4567")
print m.group()
# 06

m = re.match("<H1>(.*)</H1>", "<H1>title</H1>")
print m.group()
# <H1>title</H1>

print m.group(1)
# title

print m.group(0)
# <H1>title</H1>


m = re.match("a(.*)fa(a(.*)t)", "almafaalatt")
print m.group(1)
# lma

print m.group(2)
# alatt

print m.group(3)
# lat

print m.groups()
# ('lma', 'alatt', 'lat')

print m.group(2,1,3,2)
# ('alatt', 'lma', 'lat', 'alatt')

