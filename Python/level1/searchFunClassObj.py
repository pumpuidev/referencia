#! /usr/bin/env python
# -*- coding: utf-8 -*-

from objSearch import Search
import sys, getInfoFun_3_1, getInfoClass

class SearchFun (Search):
    def getInfo(self, name, file) :
        return getInfoFun_3_1.getInfo(name, file)

    def io(self) :
        print "Milyen függvényt keresel?"
        funname = str(raw_input())
        print "Milyen könyvtáron belül?"
        path = str(raw_input())
        infos = self.search(funname, path)
        if infos :
            print "A függvény megtalálható:"
            for file, fun, doc in infos:
                print "\tA(z) " + file + " fileban,"
                print "\t  " + fun + " szignatúrával."
                if doc : print "\t  Leírása: " + doc
                print ""
        else:
            print "Nem találtam a megadott helyen ilyen függvényt!"


class SearchClass (Search):
    def getInfo(self, name, file) :
        return getInfoClass.getInfo(name, file)

    def io(self) :
        print "Milyen osztályt keresel?"
        classname = str(raw_input())
        print "Milyen könyvtáron belül?"
        path = str(raw_input())
        infos = self.search(classname, path)
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
        if sys.argv[1] == "-f": 
            s = SearchFun()
            s.io()
        elif sys.argv[1] == "-c": 
            s = SearchClass()
            s.io()    
        else: print usage        
    else: print usage    
    
