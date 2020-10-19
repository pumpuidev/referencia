#! /usr/bin/env python
# -*- coding: utf-8 -*-

import os, re
from getInfoFun_2_0 import getInfo



def search(funname, path) :
    """ A megadott könyvtárstruktúrában a Python fájlokban keresi 
       a megadott nevű függvény szignatúráját és egysoros dokumentációs 
       string-jét (a 2.0-ás getInfo alapján)"""
    infos = []
    for root, dirs, files in os.walk(path): 
        for file in files :
            if re.match(".*\.py", file) :
               full = os.path.join(root, file) 
               sig, doc = getInfo(funname, full) 
               if sig : infos.append((full, sig, doc))
    return infos


if __name__ == "__main__":
    print "Milyen függvényt keresel?"
    funname = str(raw_input())
    print "Milyen könyvtáron belül?"
    path = str(raw_input())
    infos = search(funname, path)
    if infos :
        print "A függvény megtalálható:"
        for file, fun, doc in infos:
            print "\tA(z) " + file + " fájlban,"
            print "\t  " + fun + " szignatúrával."
            if doc : print "\t  Leírása: " + doc
            print ""
    else:
        print "Nem találtam a megadott helyen ilyen függvényt!"
