#! /usr/bin/env python
# -*- coding: utf-8 -*-

# A grid() metódus bemutatása (2) :
from Tkinter import *

abl1 = Tk()
# a 'Label' és 'Entry' widgetek létrehozása:
txt1 = Label(abl1, text ='Első mező :')
txt2 = Label(abl1, text ='Második :')
txt3 = Label(abl1, text ='Harmadik :')
mezo1 = Entry(abl1)
mezo2 = Entry(abl1)
mezo3 = Entry(abl1)

# egy bitmap képet tartalmazó 'Canvas' widget létrehozása :
can1 = Canvas(abl1, width =160, height =160, bg ='white')
photo = PhotoImage(file ='hatter.gif')
item = can1.create_image(80, 80, image =photo)

# laptördelés a'grid' metódus segítségével :
txt1.grid(row =1, sticky =E)
txt2.grid(row =2, sticky =E)
txt3.grid(row =3, sticky =E)
mezo1.grid(row =1, column =1)
mezo2.grid(row =2, column =1)
mezo3.grid(row =3, column =1)
can1.grid(row =1, column =2, rowspan =3, padx =10, pady =5)

# indítás :
abl1.mainloop()
