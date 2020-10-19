#! /usr/bin/env python
# -*- coding: utf-8 -*-

import os, re
from getInfoClass import getInfo



def search(classname, path) :
    """ A megadott könyvtárstruktúrában a Python fájlokban keresi 
       a megadott nevű osztály szignatúráját és az örökölt osztályokat"""
    infos = []
    for root, dirs, files in os.walk(path): 
        for file in files :
            if re.match(".*\.py", file) :
               full = os.path.join(root, file) 
               sig, doc = getInfo(classname, full) 
               if sig : infos.append((full, sig, doc))
    return infos


if __name__ == "__main__":
    print "Milyen osztályt keresel?"
    classname = str(raw_input())
    print "Milyen könyvtáron belül?"
    path = str(raw_input())
    infos = search(classname, path)
    if infos :
        print "Az osztály megtalálható:"
        for file, cls, parents in infos:
            print "\tA(z) " + file + " fileban,"
            print "\t  " + cls + " szignatúrával."
            if parents : 
                print "\t  A következő osztályoktól örököl: "
                print "\t ",
                for par in parents : print par,
            print ""
    else:
        print "Nem találtam a megadott helyen ilyen osztályt!"

