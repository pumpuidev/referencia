#! /usr/bin/env python
# -*- coding: utf-8 -*-

import re


def getInfo(funname, file) :
    """Visszaadja a szignatúrát és a dokumentációs stringet, 
        ha van adott nevű fv a fájlban."""
    docStrPat  = re.compile("\s*(?P<z>['\"])(?!(?P=z))(.*)(?P=z)")    
    docMultBegin = re.compile("\s*((?:''')|(?:\"\"\"))(.*)", re.S)
    f = open(file, "r")
    line = f.readline()
    while line :
        m = re.match("def\s+(" + funname + "\s*\(.*\))\s*:(.*)", line, re.S)
        if m : 
            sig_part = m.group(1)
            rem_part = m.group(2)
            d_one = re.match(docStrPat, rem_part)
            if d_one : return(sig_part, d_one.group(2));
            else :
                d_mult_b = re.match(docMultBegin, rem_part)
                if d_mult_b :
                    begin_sign = d_mult_b.group(1)
                    line = d_mult_b.group(2)
                    info = ""
                    d_mult_e = re.match("(.*)" + begin_sign,line)
                    while not d_mult_e :
                        info = info + line
                        line = f.readline()
                        d_mult_e = re.match("(.*)" + begin_sign,line)
                    info = info + d_mult_e.group(1)
                    return(sig_part, info)
                elif (not rem_part) or rem_part.isspace() :
                    line = f.readline()
                    while line.isspace() : line = f.readline(); 
                    d_one = re.match(docStrPat, line)
                    if d_one : return(sig_part, d_one.group(2));
                    else :
                        d_mult_b = re.match(docMultBegin, line)
                        if d_mult_b :
                            begin_sign = d_mult_b.group(1)
                            line = d_mult_b.group(2)
                            info = ""
                            d_mult_e = re.match("(.*)" + begin_sign,line)
                            while not d_mult_e :
                                info = info + line
                                line = f.readline()
                                d_mult_e = re.match("(.*)" + begin_sign,line)
                            info = info + d_mult_e.group(1)
                            return(sig_part, info)
                        else: return (sig_part, "");
                else: return (sig_part, "");        
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
	
	
