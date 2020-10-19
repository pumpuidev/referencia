#! /usr/bin/env python
# -*- coding: utf-8 -*-

from Tkinter import *
# eseménykezelők
# definiálása
def move():
    "a labda elmozdulása"
    global x1, y1, dx, dy, flag, speed
    setColor()
    x1, y1 = x1 +dx, y1 + dy
    if x1 > 360:
        x1, dx, dy = 360, 0, 15
    if y1 > 360:
        y1, dx, dy = 360, -15, 0
    if x1 < 10:
        x1, dx, dy = 10, 0, -15
    if y1 < 10:
        y1, dx, dy = 10, 15, 0
    can1.coords(oval1, x1, y1, x1+30, y1+30)
    can1.itemconfig(oval1, fill = color)
    
    if flag > 0:
        kesleltetes = 100 / speed 
        abl1.after(kesleltetes, move) # megadott millisec után ciklus

def stop_it():
    "az animáció leáll"
    global flag
    flag = 0

def start_it():
    "az animáció elindítása"
    global flag
    if flag == 0:
        flag = 1
        move()
    
def setSpeed(n):
    "a sebesség állítása"
    global speed
    speed = int(n)  
    
def setColor():
    "a szín állítása"
    global color
    c = listBox.curselection()
    if c :
       n = int(c[0])
       color = colorvalues[n]
       
    
    
#========== Főprogram =============
# a következő változókat globális változókként fogjuk használni :
x1, y1 = 10, 10 # kezdő koordináták
dx, dy = 15, 0 
flag =0 
speed = 5
color = 'red'

# A fő-widget létrehozása ("master") :
abl1 = Tk()
abl1.title("Animációs gyakorlat Tkinter-rel")

# a "slave" widget-ek létrehozása:
can1 = Canvas(abl1,bg='dark grey',height=400,width=400)
can1.pack(side=LEFT)
oval1 = can1.create_oval(x1, y1, x1+30, y1+30, width=2, fill=color)
Button(abl1,text='Kilép',command=abl1.quit).pack(side=BOTTOM)
Button(abl1,text='Indít',command=start_it).pack()
Button(abl1,text='Leállít',command=stop_it).pack()
scale = Scale(abl1, length = 200, label = "Sebesség :", orient = HORIZONTAL, 
            from_ = 1, to = 10, command = setSpeed, showvalue = 0, tickinterval = 1)
scale.set(5)
scale.pack()


colors = ["piros", "kék", "zöld", "sárga", "lila", "szürke", "barna", "fekete", 
                    "fehér", "narancssárga", "rózsaszín", "sötét zöld"]
colorvalues = ["red", "blue", "green", "yellow", "purple", "grey", "brown", "black", 
                    "white", "orange", "pink", "dark green"]
                    
listFrame = Frame(abl1)
listFrame.pack(padx=5, pady=5)
                   
listBox = Listbox(listFrame, selectmode = SINGLE)
for c in colors :
    listBox.insert(END, c)
listBox.pack(side = LEFT, fill=Y)     
scrollBar = Scrollbar(listFrame)
scrollBar.pack(side = RIGHT, fill=Y)
scrollBar.config(command=listBox.yview)
listBox.config(yscrollcommand=scrollBar.set)



# az eseményfogadó indítása (főciklus) :
abl1.mainloop()
