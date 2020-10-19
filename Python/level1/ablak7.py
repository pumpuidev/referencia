#! /usr/bin/env python
# -*- coding: utf-8 -*-

# Tömörítés és checkbox példa :
from Tkinter import *

abl1 = Tk()

Label(abl1, text = 'Első mező :').grid(sticky = E)
Label(abl1, text = 'Második :').grid(sticky = E)
Label(abl1, text = 'Harmadik :').grid(sticky = E)

mezo1 = Entry(abl1)
mezo2 = Entry(abl1) 
mezo3 = Entry(abl1) 
mezo1.grid(row = 0, column = 1) 
mezo2.grid(row = 1, column = 1) 
mezo3.grid(row = 2, column = 1)

# Checkbox létrehozása
chek1 = Checkbutton(abl1, text ='Checkbox példa')
chek1.grid(row = 3, column = 0, columnspan = 2)

can1 = Canvas(abl1, width = 160, height = 160, bg ='white')
photo = PhotoImage(file ='hatter.gif')
can1.create_image(80,80, image = photo)
can1.grid(row = 0, column = 2, rowspan = 4, padx = 10, pady = 5)

# indítás :
abl1.mainloop()
