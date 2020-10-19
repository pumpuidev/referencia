#! /usr/bin/env python
# -*- coding: iso-8859-2 -*-

from turtle import *

delay(40)

print position()
# (0.00,0.00)

forward(120)
print position()
# (120.00,0.00)

backward(20)
print position()
# (100.00,0.00)

forward(-30)
print position()
# (70.00,0.00)

print heading()
# 0.0

left(90)
print heading()
# 90.0

right(30)
print heading()
# 60.0

home()
print position(), heading()
# (0.00,0.00) 0.0

setpos(200,150)
print position()
# (200.00,150.00)

setx(-30)
print position()
# (-30.00,150.00)

sety(12)
print position()
# (-30.00,12.00)

setheading(90)
print heading()
# 90.0


exitonclick()
