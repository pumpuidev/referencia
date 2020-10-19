#! /usr/bin/env python
# -*- coding: utf-8 -*-

import re


def getInfo(funname, file) :
    "Visszaadja a szignatúrát, ha van adott nevű fv a fájlban."
    f = open(file, "r")
    for line in f :
        m = re.match("def\s+(" + funname + "\s*\(.*?\))\s*:",line)
        if m : return m.group(1)
    return ""    


if __name__ == "__main__":
    print "Milyen függvényt keresel?"
    funname = str(raw_input())
    print "Milyen fájlban?"
    file = str(raw_input())
    info = getInfo(funname, file)
    if info :
        print "A függvény megtalálható a " + file + " fájlban," 
        print "   " + info + " szignatúrával.\n"
    else:
        print "Nem találtam a megadott helyen ilyen függvényt!"
