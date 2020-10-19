#! /usr/bin/env python
# -*- coding: iso-8859-2 -*-

from turtle import *
from pascal import pascal

delay(1)

def negyzet(meret, szin):
    "megadott méretű és színű négyzetet rajzoló függvény"
    color(szin)
    for i in range(4):
        forward(meret)
        right(90)

def szoveges_negyzet(string, meret, szin):
    negyzet(meret, szin)
    penup()
    forward(meret/2)
    right(90)
    forward((meret/2)+8)
    pendown()
    write(string, align = "center", font=("Courier", 12, "normal"))
    penup()
    backward((meret/2)+8)
    left(90)
    backward(meret/2)
    pendown()
    
def szoveges_negyzetek(y, meret, szin, szovegek):
    x = (len(szovegek)* meret)/2 
    j = 0
    for i in range(-x,x,meret):
        penup()
        setpos(i,y)
        pendown()
        szoveges_negyzet(szovegek[j], meret, szin)
        j += 1 

hideturtle()
width(2)

db = 8
list = [1]
y = 200
szoveges_negyzetek(y, 50, "blue", map( str, list))
for i in range(1, db+1):
    list = pascal(list)
    y = y - 50
    szoveges_negyzetek(y, 50, "blue", map( str, list))


exitonclick()
