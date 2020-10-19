#! /usr/bin/env python
# -*- coding: utf-8 -*-

from Tkinter import *

def drawline():
    "Vonal rajzolása a can1 canvasra (vászonra)"
    global x1, y1, x2, y2
    can1.create_line(x1,y1,x2,y2,width=2,fill=color)
    
    # a koordináták módosítása a következő egyenes számára :
    if y1 > 10 : 
        y2, y1 = y2 + 10, y1 - 10
    elif x2 > 10 : 
        x1, x2 = x1 + 10, x2 - 10
    else :
        x1, y1, x2, y2 = 10, 290, 290, 10        

def changeTo(str):
      global color
      color = str
      drawline()

def clear():
    global x1, y1, x2, y2
    can1.delete(ALL)
    x1, y1, x2, y2 = 10, 290, 290, 10

#------ Főprogram -------

x1, y1, x2, y2 = 10, 290, 290, 10 # az egyenes koordinátái

abl1 = Tk()
can1 = Canvas(abl1,bg='dark grey',height=300,width=300)
can1.pack(side=LEFT)

gomb1 = Button(abl1,text='Kilép',command = abl1.quit, width=7)
gomb1.pack(side=BOTTOM, pady = 4)

gomb2 = Button(abl1,text='Törlés',command = clear, width=7 )
gomb2.pack(side=BOTTOM, pady = 2)

gomb8 = Button(abl1,text='Barna',command = lambda : changeTo("brown"), width=7)
gomb8.pack(pady = 2)

gomb3 = Button(abl1,text='Piros',command = lambda : changeTo("red"), width=7)
gomb3.pack(pady = 2)

gomb4 = Button(abl1,text='Zöld',command = lambda : changeTo("green"), width=7)
gomb4.pack(pady = 2)

gomb5 = Button(abl1,text='Kék',command = lambda : changeTo("blue"), width=7)
gomb5.pack(pady = 2)

gomb6 = Button(abl1,text='Narancs',command = lambda : changeTo("orange"), width=7)
gomb6.pack(pady = 2, padx = 2)

gomb7 = Button(abl1,text='Lila',command = lambda : changeTo("purple"), width=7)
gomb7.pack(pady = 2)


abl1.mainloop() # eseményfogadó indítása

