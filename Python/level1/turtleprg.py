#! /usr/bin/env python
# -*- coding: iso-8859-2 -*-

from turtle import *

delay(1)

def negyzet(meret, szin):
    "megadott méretű és színű négyzetet rajzoló függvény"
    color(szin)
    for i in range(4):
        forward(meret)
        right(90)

def negyzetek(x, y, meret, szin):
    for i in range(-x,x,meret):
        penup()
        setpos(i,y)
        pendown()
        negyzet(meret,szin)



hideturtle()
width(2)

negyzetek(200, -200, 50, "blue")
negyzetek(175, -150, 50, "blue")
negyzetek(150, -100, 50, "red")
negyzetek(125, -50, 50, "red")
negyzetek(100, 0, 50, "green")
negyzetek(75, 50, 50, "green")
negyzetek(50, 100, 50, "yellow")
negyzetek(25, 150, 50, "yellow")

exitonclick()
