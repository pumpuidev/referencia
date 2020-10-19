#! /usr/bin/env python
# -*- coding: iso-8859-2 -*-

import os

print os.path.join("ea6","ospath.py")
# ea6/ospath.py    # linuxon...

print os.path.join("scny", "ea6", "ospath.py")
# scny/ea6/ospath.py    # linuxon...

print os.path.exists(os.getcwd())
# True

print os.path.exists(os.path.join("nemvan","nemvan.py"))
# False

os.chdir("..")
print os.path.isfile(os.path.join("ea6","ospath.py")) # linkre is igazat ad, ha fájlra mutat
# True

print os.path.isdir(os.path.join(os.getcwd(),"ea6")) # linkre is igazat ad, ha könyvtárra mutat
# True

print os.path.islink(os.path.join(os.getcwd(),"ea6"))
# False

print os.path.split(os.path.join("ea6","ospath.py"))
# ('ea6', 'ospath.py')

print os.path.splitdrive(os.getcwd()) # Windowson érdekes 
# ('', '/home/matej/scny')    # linuxon...

print os.path.basename(os.getcwd())
# scny

print os.path.dirname(os.getcwd())
# /home/matej


def kiir(x, dir, files) :
    print dir + "  konyvtar"  
    for file in files :
        print file + "  fajl" + x,
    print ""    

os.chdir("ea6")
os.mkdir("newtmp")
os.chdir("newtmp")
f = open("tmp1.py","w")
f.close()
f = open("tmp2.py","w")
f.close()
os.mkdir("subtmp")
os.chdir("subtmp")
f = open("tmp3.py","w")
f.close()
os.chdir(os.path.join("..",".."))

os.path.walk("newtmp", kiir, ";")  # ehelyett vezették be az os.walk függvényt... 
# newtmp  konyvtar
# subtmp  fajl; tmp2.py  fajl; tmp1.py  fajl; 
# newtmp/subtmp  konyvtar
# tmp3.py  fajl;

# --------------------------

def dir_delete(topdir) :
    for root, dirs, files in os.walk(topdir, topdown=False): # alulról felfelé
        for name in files:
            os.remove(os.path.join(root, name))
        for name in dirs:
            os.rmdir(os.path.join(root, name))
    os.rmdir(topdir)


dir_delete("newtmp")




