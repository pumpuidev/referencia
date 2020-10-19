#! /usr/bin/env python
# -*- coding: utf-8 -*-

import sys, os, re, getInfoFun_3_1, getInfoClass 


def search(name, path, getInfo) :
    """ A megadott könyvtárstruktúrában a Python fájlokban keresi 
       a megadott nevű függvény szignatúráját és dokumentációs 
       string-jét vagy a megadott nevű osztály szignatúráját és 
       az örökölt osztályokat (a getInfo paraméter alapján)."""
    infos = []
    for root, dirs, files in os.walk(path): 
        for file in files :
            if re.match(".*\.py", file) :
               full = os.path.join(root, file) 
               sig, doc = getInfo(name, full) 
               if sig : infos.append((full, sig, doc))
    return infos


def ioFun() :
    print "Milyen függvényt keresel?"
    funname = str(raw_input())
    print "Milyen könyvtáron belül?"
    path = str(raw_input())
    infos = search(funname, path, getInfoFun_3_1.getInfo)
    if infos :
        print "A függvény megtalálható:"
        for file, fun, doc in infos:
            print "\tA(z) " + file + " fileban,"
            print "\t  " + fun + " szignatúrával."
            if doc : print "\t  Leírása: " + doc
            print ""
    else:
        print "Nem találtam a megadott helyen ilyen függvényt!"

def ioClass() :
    print "Milyen osztályt keresel?"
    classname = str(raw_input())
    print "Milyen könyvtáron belül?"
    path = str(raw_input())
    infos = search(classname, path, getInfoClass.getInfo)
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


if __name__ == "__main__":
    usage = """ Paraméterezés: "-f" fájl keresés
                "-c" osztály keresés """
    if len(sys.argv) == 2 :
        if sys.argv[1] == "-f": ioFun()
        elif sys.argv[1] == "-c": ioClass()
        else: print usage        
    else: print usage    




