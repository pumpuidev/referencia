#! /usr/bin/env python
# -*- coding: iso-8859-2 -*-

import os
import stat

os.environ # k�rnyezeti v�ltoz�k

print os.name

if os.name == "nt" :
    print os.environ["OS"]
    # Windows_NT
elif os.name == "posix" :
    print os.environ["USER"] 
    # matej


os.getcwd() # az aktu�lis munkak�nyvt�r



if not ("tmp" in os.listdir(os.getcwd()) ) : 
    os.mkdir("tmp") # nem szabad l�tezzen ilyen nev� k�nyvt�r

os.chdir("tmp")

f = open("proba.py","w")
f.write("#! /usr/bin/env python\n\n")
f.write("print 'Proba szoveg!'")
f.close()

print os.listdir(os.getcwd()) # a megadott k�nyvt�r tartalma ".", ".." n�lk�l
# ['proba.py']


if os.name == "nt" :
    os.system("proba.py") # parancs v�grehajt�sa
    # Proba szoveg!
elif os.name == "posix" :
    os.chmod("proba.py", stat.S_IRUSR) # jogok be�ll�t�sa (l�sd stat modul)
    os.system("ls -l") 
    # �sszesen 4
    # -r-------- 1 matej matej 21 2010-03-09 18:25 proba.py
   
    os.chmod("proba.py", stat.S_IRWXU | stat.S_IWGRP | stat.S_IROTH) 
    os.system("ls -l") 
    # �sszesen 4
    # -rwx-w-r-- 1 matej matej 21 2010-03-09 18:33 proba.py
    
    os.system("./proba.py")
    # Proba szoveg!


os.system("dir")
# proba.py

os.rename("proba.py", "try.py")

os.system("dir")
# try.py

os.remove("try.py")
print os.listdir(os.getcwd())
# []

os.chdir("..")
os.rmdir("tmp") # csak �res k�nyvt�r t�r�lhet�


# --------------------------------

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
os.chdir("..")

for root, dirs, files in os.walk(os.getcwd()): # fentr�l lefel� bej�rja a k�nyvt�rstrukt�r�t
    print "Root: ", root
    if dirs != [] :
        print "Dirs: ",
        for name in dirs :
            print name,
        print ""    
    if files != [] :
        print "Files: ",
        for name in files :
            print name,
        print ""

# Root:  /home/matej/scny/ea6/newtmp
# Dirs:  subtmp 
# Files:  tmp2.py tmp1.py 
# Root:  /home/matej/scny/ea6/newtmp/subtmp
# Files:  tmp3.py 


def dir_delete(topdir) :
    for root, dirs, files in os.walk(topdir, topdown=False): # alulr�l felfel�
        for name in files:
            os.remove(os.path.join(root, name))
        for name in dirs:
            os.rmdir(os.path.join(root, name))
    os.rmdir(topdir)

os.chdir("..")
dir_delete("newtmp")

