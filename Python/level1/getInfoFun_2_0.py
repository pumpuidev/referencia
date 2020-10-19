#! /usr/bin/env python
# -*- coding: utf-8 -*-

import re


def getInfo(funname, file) :
    """Visszaadja a szignatúrát és az egysoros dokumentációs stringet, 
        ha van adott nevű fv a fájlban."""
    docStrPat  = re.compile("\s*(?P<z>['\"])(?!(?P=z))(.*?)(?P=z)")    
    f = open(file, "r")
    line = f.readline()
    while line :
        m = re.match("def\s+(" + funname + "\s*\(.*\))\s*:(.*)",line)
        if m : 
            dm = re.match(docStrPat, m.group(2))
            if dm : return(m.group(1), dm.group(2));
            elif (not m.group(2)) or m.group(2).isspace() :
                line = f.readline()
                while line.isspace() : line = f.readline(); 
                dm = re.match(docStrPat, line)
                if dm : return(m.group(1), dm.group(2));
                else: return (m.group(1), "");
            else: return (m.group(1), "");    
        line = f.readline()
    return ("", "")    


if __name__ == "__main__":
    print "Milyen függvényt keresel?"
    funname = str(raw_input())
    print "Milyen fájlban?"
    file = str(raw_input())
    info, doc = getInfo(funname, file)
    if info :
        print "A függvény megtalálható a " + file + " fájlban," 
        print "   " + info + " szignatúrával."
        if doc : print "Leírása: " + doc 
        print ""
    else:
        print "Nem találtam a megadott helyen ilyen függvényt!"

