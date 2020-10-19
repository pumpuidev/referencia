#! /usr/bin/env python
# -*- coding: iso-8859-2 -*-

import re

# Regularis kifejezesek

'.' # egy db barmilyen karakter, kiveve '\n', ha a re.DOTALL flag be van allitva '\n' is lehet

'^' # a szoveg elejere illeszkedik

'$' # a szoveg vegere illeszkedik

m = re.search("^a.", "almafalattalma")
print m.span()
# (0,2)

m = re.search("ma$", "almafalattalma")
print m.span()
# (12,14)

# ----------------------------------------------

'*' # a megelozo minta 0 vagy tobb ismetlodesere illeszkedik (maximalis hosszusagban)

'+' # a megelozo minta 1 vagy tobb ismetlodesere illeszkedik (maximalis hosszusagban)

'?' # a megelozo minta 0 vagy 1 ismetlodesere illeszkedik

'*?' # a megelozo minta 0 vagy tobb ismetlodesere illeszkedik (minimalis hosszusagban)

'+?' # a megelozo minta 1 vagy tobb ismetlodesere illeszkedik (minimalis hosszusagban)

print re.findall("a*", "aaabaaaaaabba")
['aaa', '', 'aaaaaa', '', '', 'a', '']

print re.findall("a+", "aaabaaaaaabba")
['aaa', 'aaaaaa', 'a']

print re.findall("a?b+c*", "abbbc abccc aabc bbb ccc bcccca ac abc")
['abbbc', 'abccc', 'abc', 'bbb', 'bcccc', 'abc']

m = re.match("<.*>", "<H1>title</H1>")
print m.group()
# <H1>title</H1>

m = re.match("<.*?>", "<H1>title</H1>")
print m.group()
# <H1>

m = re.search("<.*?>", "<H1>title</H1>")
print m.group()
# <H1>

m = re.search("<.*?>$", "<H1>title</H1>")
print m.group()
# <H1>title</H1>


# ----------------------------------------------


'{n}' # a megelozo minta n db ismetlodesere illeszkedik 

'{m,n}' # a megelozo minta m es n kozotti ismetlodesere illeszkedik (maximalis hosszusagban)

'{m,n}?' # a megelozo minta m es n kozotti ismetlodesere illeszkedik (minimalis hosszusagban)

print re.findall("a?.{3}c*", "ccc abc aabb abfgcccc ahjfubc")
# ['ccc', ' abc', ' aa', 'bb ', 'abfgcccc', ' ah', 'jfu']

m = re.match("a?b{3,6}", "abbbbbbbbb")
print m.group()
# abbbbbb

m = re.match("a?b{3,6}?", "abbbbbbbbb")
print m.group()
# abbb


# ----------------------------------------------


f = open("zh.txt", "r")
f2 = open("eredmeny.txt", "w")

for line in f:
    m = re.search(".{7}\.ELTE", line)
    if m != None :
        f2.write(m.group())
        m2 = re.search("eredmény:.*$", line)
        if m2 != None:
            e = m2.group()
            f2.write(e[10:]) # az 'é' két karakternek számít
        else:
            f2.write(" nincs jegy")    
        f2.write("\n") 

f.close()
f2.close()

f = open("zh.txt", "r")
f2 = open("eredmeny2.txt", "w")

for line in f:
    m = re.search(".{7}\.ELTE", line)
    if m != None :
        f2.write(m.group())
        e = line.rsplit(":", 1)
        f2.write(e[1])
         



