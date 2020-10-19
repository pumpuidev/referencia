#! /usr/bin/env python
# -*- coding: utf-8 -*-

from Tkinter import *

abl1 = Tk()
tex1 = Label(abl1, text='Jó napot kívánok!\n', fg='red')
tex1.pack()
gomb1 = Button(abl1, text='Kilép', command = abl1.destroy)
gomb1.pack()
abl1.mainloop()
