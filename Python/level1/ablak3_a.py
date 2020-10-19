#! /usr/bin/env python
# -*- coding: utf-8 -*-

from Tkinter import *
from math import *

def kiertekel(event):
   cimke.configure(text = "Eredmény = " + str(eval( mezo.get())))

# ----- Főprogram : -----
ablak = Tk()
mezo = Entry(ablak)

# Így kicsit mást csinál, mint kellene:
mezo.bind("<Enter>", kiertekel)
mezo.pack()
mezo.insert(0,"1")

cimke = Label(ablak)
cimke.pack()

ablak.mainloop()

#<KeyPress> Egy billentyű lenyomása
#<KeyPress-a> A kis 'A' lenyomása (kisbetű)
#<KeyPress-A> A nagy ‘A' lenyomása (nagybetű)
#<Return> Enter lenyomása
#<Escape> Escape lenyomása
#<Up> <Down> Nyílbillentyűk lenyomása
#<Button-1> Kattintás a balegérgombbal
#<Button-2> Kattintás a középső (vagy mindkét) egérgombbal
#<Button-3> Kattintás a jobbegérgombbal
#<ButtonRelease> A balegérgomb kattintás vége
#<Motion> Az egér mozgatása
#<B1-Motion> Az egér mozgatása balegérgomb kattintással
#<Enter> <Leave> Az egér egy widget fölé mozog, vagy fölül elmozog
#<Configure> Ablak átméretezése

