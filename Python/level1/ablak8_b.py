#! /usr/bin/env python
# -*- coding: utf-8 -*-

from Tkinter import *
# eseménykezelők
# definiálása
def move():
    "a labda elmozdulása"
    global x1, y1, dx, dy, flag, speed
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
    can1.itemconfig(oval1, fill = color.get())
    
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
    
def draw():
    "a szín újrarajzolása"
    can1.itemconfig(oval1, fill = color.get())
       
    
    
#========== Főprogram =============
# a következő változókat globális változókként fogjuk használni :
x1, y1 = 10, 10 # kezdő koordináták
dx, dy = 15, 0 
flag =0 
speed = 5


# A fő-widget létrehozása ("master") :
abl1 = Tk()
abl1.title("Animációs gyakorlat Tkinter-rel")


# A színt tartalmazó változó létrehozása:
color = StringVar(abl1)
color.set("red")


# a "slave" widget-ek létrehozása:
can1 = Canvas(abl1,bg='dark grey',height=400,width=400)
can1.pack(side=LEFT)
oval1 = can1.create_oval(x1, y1, x1+30, y1+30, width=2, fill=color.get())
Button(abl1,text='Kilép',command=abl1.quit).pack(side=BOTTOM)
Button(abl1,text='Indít',command=start_it).pack()
Button(abl1,text='Leállít',command=stop_it).pack()
scale = Scale(abl1, length = 200, label = "Sebesség :", orient = HORIZONTAL, 
            from_ = 1, to = 10, command = setSpeed, showvalue = 0, tickinterval = 1)
scale.set(5)
scale.pack()

colors = ["piros", "kék", "zöld", "sárga", "lila"]
colorvalues = ["red", "blue", "green", "yellow", "purple"]

#listFrame = Frame(abl1)
#listFrame.pack(padx=5, pady=5)

for n in range(0, len(colors)):
    radio = Radiobutton(abl1, text = colors[n], variable = color,
                    value = colorvalues[n], command = draw, anchor = W)
    radio.pack(anchor = W)

   

# az eseményfogadó indítása (főciklus) :
abl1.mainloop()
