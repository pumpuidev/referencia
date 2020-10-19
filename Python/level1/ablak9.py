#! /usr/bin/env python

from Tkinter import *

root = Tk()
root.withdraw()

menubar = Menu()

filemenu = Menu(menubar)

filemenu.add_command(label="New")
filemenu.add_command(label="Open...")
filemenu.add_command(label="Close")
filemenu.add_separator()
filemenu.add_command(label="Quit", command=root.quit)

editmenu = Menu(menubar)

editmenu.add_command(label="Cut")
editmenu.add_command(label="Copy")
editmenu.add_command(label="Paste")

helpmenu = Menu(menubar, name='help')

helpmenu.add_command(label="About...")

menubar.add_cascade(label="File", menu=filemenu)
menubar.add_cascade(label="Edit", menu=editmenu)
menubar.add_cascade(label="Help", menu=helpmenu)

top = Toplevel(root, menu = menubar)
top.protocol("WM_DELETE_WINDOW", root.quit)
top.mainloop()



