#! /usr/bin/env python
# -*- coding: utf-8 -*-


x = "global_x"
y = "global_y"


def localfv() :
    global x
    
    print "A függvény elején x:", x
    #print "A függvény elején y:", y
    x = "changed_x"
    y = "changed_y"
    print "A függvényben x:", x, "y:", y

print "Kezdetben x:", x, "y:", y
localfv()
print "A függvényhívás után x:", x, "y:", y

#Kezdetben x: global_x y: global_y
#A függvény elején x: global_x
#A függvényben x: changed_x y: changed_y
#A függvényhívás után x: changed_x y: global_y
