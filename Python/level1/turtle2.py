#! /usr/bin/env python
# -*- coding: iso-8859-2 -*-

from turtle import *

delay(30)

print position(), heading()
#(0.00,0.00) 0.0

circle(50) # kört rajzol
print position(), heading()
#(-0.00,0.00) 0.0

reset()

circle(50,180) # félkört rajzol
print position(), heading()
#(0.00,100.00) 180.0

reset()

circle(50,270,5) 
print position(), heading()
#(-50.00,50.00) 270.0

reset()

circle(100,360,5) 
print position(), heading()
#(-0.00,0.00) 0.0

reset()

circle(50,270,50)
print position(), heading()
#(-50.00,50.00) 270.0

exitonclick()
