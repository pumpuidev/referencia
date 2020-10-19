#! /usr/bin/env python
# -*- coding: iso-8859-2 -*-

from turtle import *

delay(200)

dot()
print position(), heading()
#(0.00,0.00) 0.0


forward(50)
dot(20)
print position(), heading()
#(50.00,0.00) 0.0

forward(50)
dot(40,"red")
print position(), heading()
#(100.00,0.00) 0.0

color("blue")
forward(50)

st1 = stamp()
print st1
# 10

right(-90)
forward(50)

st2 = stamp()
print st2
# 11

left(-90)
forward(50)

clearstamp(st1)

stamp()

backward(100)

clearstamps()

color("red")
left(90)
forward(50)

undo()
undo()

exitonclick()
