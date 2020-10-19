#! /usr/bin/env python
# -*- coding: iso-8859-2 -*-

from turtle import *

delay(40)

forward(100)
write("szoveg")

color("red")
left(90)
forward(100)
write("ujszoveg", align = "center", font=("Courier", 12, "normal"))

hideturtle()
penup()
home()
pendown()
right(180)
forward(50)
showturtle()

shape("turtle") # "arrow", "turtle", "circle", "square", "triangle", "classic"
stamp()
right(90)
forward(50)


exitonclick()
