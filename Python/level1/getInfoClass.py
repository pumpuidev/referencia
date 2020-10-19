#! /usr/bin/env python
# -*- coding: utf-8 -*-

import re


def getInfo  (classname, file) :
    """Visszaadja a szignatúrát és az örökölt osztályokat, 
              ha van adott nevű osztály a fájlban."""
    f = open(file, "r")
    for line in f :
        m = re.match("class\s+(" + classname + "\s*(\((.*)\))?)\s*:",line)
        if m :
            if m.group(3) :  
                return (m.group(1), m.group(3).split(",")) 
            else: return (m.group(1), "")
    return ("","")    


if __name__ == "__main__":
    print "Milyen osztályt keresel?"
    classname = str(raw_input())
    print "Milyen fájlban?"
    file = str(raw_input())
    info, parents = getInfo(classname, file)
    if info :
        print "Az osztály megtalálható a " + file + " fájlban," 
        print "   " + info + " szignatúrával."
        if parents :
            print "A következő osztályokból örököl:"
            for par in parents : print par,
        print ""
    else:
        print "Nem találtam a megadott helyen ilyen osztályt!"

