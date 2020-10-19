#! /usr/bin/env python
# -*- coding: iso-8859-2 -*-

import re

# Regularis kifejezesek

'(?: )' # csoportos�t�s csoport val�di l�trehoz�sa n�lk�l

m = re.match("a(?:.*)fa(a(.*)t)", "almafaalatt")
print m.group(1)
# alatt

print m.groups()
# ('alatt', 'lat')

m = re.match("(?:a.*?a){2}(.*)", "almaalmapiros")
print m.group(1)
# piros

'\szam' # a megadott sorsz�m� csoportra hivatkozik

m = re.match(r"(.).*?\1", "almafaalatt") # raw text
print m.group()
# alma

print "(.)(.).*?\1"
# (.)(.).*?

print r"(.)(.).*?\1"
# (.)(.).*?\1

m = re.match(r"(.)(.).*?\1", "almafaalatt") 
print m.group()
# alma

m = re.match(r"(?:.)(.).*\1", "almafaalatt") 
print m.group()
# almafaal

'(?P<name> )' # n�vvel ell�tott csoport l�trehoz�sa

'(?P=name)'   # az adott nev� csoportra illeszked� minta

m = re.match("(?P<gy>.*)fa(.*)(?P=gy)", "almafaalattalma")
print m.group()
# almafaalattalma

print m.group('gy')
# alma

print m.groups()
# (alma, alatt)


print re.sub("<H1>(.*)</H1>", r"\1", "<H1>title</H1>")   #raw string
# title

print re.sub("<H1>(?P<t>.*)</H1>", "\g<t>", "<H1>title</H1>")
# title


'(?= )' # a keresett minta ut�ni stringre illeszt

m = re.match("(.*)(?=fa)", "almafaalatt")
print m.group()
# alma


'(?! )' # a keresett minta ut�ni string nem lehet a megadott

m = re.search("al(..)(?!fa)", "almafaalatt")
print m.group()
# alat


'(?<= )' # a keresett minta el�tti stringre illeszt (fix hossz� kell legyen)

m = re.search("(?<=a...)\w{2}", "almafaalatt")
print m.group()
# fa


'(?<! )' # a keresett minta el�tti string nem lehet a megadott (fix hossz� kell legyen)

m = re.search("(?<!a...)fa(.*)", "almafaalattkortefamogott")
print m.group()
# famogott

m = re.match("(?<!a...)a.+", "almafaalatt")
print m.group()
# almafaalatt


'(?(id/name)yes-pattern|no-pattern)' # Ha az adott sz�m�/nev� csoport l�tezik a 
      # yes-pattern-nek ellenkez� esetben a no-pattern-nek kell illeszkednie (az ut�bbi opcion�lis)
      
m = re.match("(<)?[^<]*(?(1)>)", "<szoveg>blabla")
print m.group()
# <szoveg>

m = re.match("(<)?[^<]*(?(1)>)", "blabla<szoveg>")
print m.group()
# blabla


# -----------------------------------------------


f = open("proba.html", "r")
f2 = open("links.txt", "w")

for line in f:
    for m in re.finditer("(?<=href=\")(http:.+?)(?=\")", line):
        f2.write(m.group())
        f2.write("\n")

f.close()
f2.close()
# -----------------------------------------------

            
def ertek(pont, minta) :
    for i in minta:
        if (int(i[0]) <= pont) and (pont <= int(i[1])):
            return i[2]
    return "Nincs megfelel� hat�r: " + str(pont)

def myInt(x) :
    if x.isdigit():
       return int(x)
    else:
       return 0 

def ertekeles(inf, outf) :
    hatarok = []
    for line in inf:
        tmp = line.strip()
        m = re.match("(\d+)[\s\-]+(\d+)[\s:]+(\d+)", tmp)
        if m :
            hatarok.append(m.group(1,2,3))
        else :
            m = re.match("(\D+)\s([^\d\s]{7}\.ELTE).*?:(.+);", tmp)
            if m : 
                pont = sum([myInt(x) for x in m.group(3).split()])
                outf.write(m.group(1) + ":")
                outf.write( ertek(pont, hatarok) + "\n")


f = open("zh2.txt", "r")
f2 = open("jegyek2.txt", "w")

ertekeles(f,f2)

f = open("zh3.txt", "r")
f2 = open("jegyek3.txt", "w")

ertekeles(f,f2)


