#! /usr/bin/env python
# -*- coding: iso-8859-2 -*-

from turtle import *

delay(40)

t2 = Turtle()
t2.color("red")
t2.forward(100)

backward(120)
t2.left(90)
right(90)
forward(100)
t2.forward(150)


penup()
home()
left(90)
width(5)
pendown()
forward(200)

fillcolor("brown")
fill("true")
circle(40)
fill("false")

exitonclick()
