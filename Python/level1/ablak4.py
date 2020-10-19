#! /usr/bin/env python
# -*- coding: utf-8 -*-

# Egérkattintás észlelése és helyének meghatározása egy ablakban :
from Tkinter import *

def mutato(event):
    cimke.configure(text = "Kattintás detektálva: X =" 
                     + str(event.x) + ", Y =" + str(event.y))

ablak = Tk()
keret = Frame(ablak, width=200, height=150, bg="light yellow")
keret.bind("<Button-1>", mutato)
keret.pack()
cimke = Label(ablak)
cimke.pack()
ablak.mainloop()
