#! /usr/bin/env python
# -*- coding: utf-8 -*-

# A grid() metódus bemutatása :
from Tkinter import *

abl1 = Tk()
txt1 = Label(abl1, text = 'Első mező :')
txt2 = Label(abl1, text = 'Második :')
mezo1 = Entry(abl1)
mezo2 = Entry(abl1)
txt1.grid(row = 0, column = 0, sticky = E) # igazítás, négy égtáj
txt2.grid(row = 1, column = 0, sticky = W) # szerint: E, W, S, N
mezo1.grid(row = 0, column = 1)
mezo2.grid(row = 1, column = 1)
abl1.mainloop()
