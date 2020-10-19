#! /usr/bin/env python
# -*- coding: Utf-8 -*-



from Tkinter import *

class MenuBar(Frame):
    """Legordulo menusor"""
    def __init__(self, boss =None):
        Frame.__init__(self, borderwidth =2, relief =GROOVE)
        ##### <File> menu #####
        fileMenu = Menubutton(self, text ='File')
        fileMenu.pack(side =LEFT, padx =5)
        me1 = Menu(fileMenu)
        me1.add_command(label ='Opciók', underline =0,
                        command = boss.options)
        me1.add_command(label ='Újrainditás', underline =0,
                        command = boss.reset)
        me1.add_command(label ='Vége', underline =0,
                        command = boss.quit)
        fileMenu.configure(menu = me1)    

        ##### <Help> menu #####
        helpMenu = Menubutton(self, text ='Help')
        helpMenu.pack(side =LEFT, padx =5)
        me1 = Menu(helpMenu)
        me1.add_command(label ='A játék elve', underline =0,
                        command = boss.principe)
        me1.add_command(label ='A propos ...', underline =0,
                        command = boss.aPropos)
        helpMenu.configure(menu = me1)
        
               
class JatekTabla(Frame):
    """Jatektabla ( n x m es negyzetracs)"""
    def __init__(self, boss =None):
        # Ez a tabla egy atmeretezheto frame-bol all, amiben egy vaszon van
        # A frame minden atmeretezesekor kiszamoljuk a racs leheto legnagyobb
        # kockameretet es a vaszon meretet ennek megfeleloen allitjuk be

        Frame.__init__(self)
        self.nrow, self.ncol = 4, 4         # Kezdotabla = 4 x 4
        # A <resize> esemeny osszekapcsolasa egy megfelelo esemenykezelovel :	
        self.bind("<Configure>", self.redim)
        # Canevas : 
        self.can =Canvas(self, bg ="dark olive green", borderwidth =0,
                         highlightthickness =1, highlightbackground ="white")
        # Az <egerkattintas esemeny > osszekapcsolasa az esemenykezelojevel :
        self.can.bind("<Button-1>", self.clic)
        self.can.pack()
        self.initGame()

    def initGame(self):
        "A jatek allapotat tarolo lista inicializalasa"
        self.state =[]               	# egymasba agyazott lista letrehozasa
        for i in range(12):             # (egyenertekű egy 12 sor x 12 oszlopos 
            self.state.append([0]*12)	#  tablaval) 

    def redim(self, event):
        "atmeretezeskor vegrehajtando műveletek"
        # Az ujrakonfiguralas esemenyevel asszocialt tulajdonsagok
        # a frame uj mereteit tartalmazzak : 
        self.width, self.height = event.width -4, event.height -4
        # A 4 pixeles külonbseg a vasznat korülvevo 'highlightbordure'
        # kompenzalasara szolgal)
        self.drawGrid()
        
    def drawGrid(self):
        "A racs kirajzolasa az opciok es a meretek függvenyeben"
        # a negyzetek lehetseges max. szelessege es hosszusaga :
        lmax = self.width/self.ncol        
        hmax = self.height/self.nrow
        # A negyzet merete ezen meretek legkisebbikevel egyenlo :
        self.side = min(lmax, hmax)
        # -> a vaszon uj mereteinek beallitasa :
        width_, height_ = self.side*self.ncol, self.side*self.nrow
        self.can.configure(width =width_, height =height_)
        # A racs kirajzolasa :
        self.can.delete(ALL)                # elozo rajzok torlese
        s =self.side                       
        for l in range(self.nrow -1):       # vizszintes vonalak
            self.can.create_line(0, s, width_, s, fill="white")
            s +=self.side
        s =self.side
        for c in range(self.ncol -1):       # függoleges vonalak
            self.can.create_line(s, 0, s, height_, fill ="white")
            s +=self.side
        # Az osszes feher illetve fekete korong kirajzolasa a jatek allapotanak megfeleloen :    
        for l in range(self.nrow):
            for c in range(self.ncol):
                x1 = c *self.side +5            # korongok merete= 
                x2 = (c +1)*self.side -5        # negyzetek merete -10
                y1 = l *self.side +5            #
                y2 = (l +1)*self.side -5
                colour =["white","black"][self.state[l][c]]
                self.can.create_oval(x1, y1, x2, y2, outline ="grey",
                                     width =1, fill =colour)     

    def clic(self, event):
        "Az egerkattintas kezelese : a korongok megforditasa"
        # A sor es az oszlop meghatarozasaval kezdjük :
        row, col = event.y/self.side, event.x/self.side
        # Majd a szomszedos 8 negyzetet kezeljük :
        for l in range(row -1, row+2):
            if l <0 or l >= self.nrow:
                continue
            for c in range(col -1, col +2):
                if c <0 or c >= self.ncol:
                    continue
                if l ==row and c ==col:
                    continue
                # Korongforditas logikai inverzioval :
                self.state[l][c] = not (self.state[l][c])
        self.drawGrid() 
           

class Ping(Frame):
    """A foprogram teste"""    
    def __init__(self):
        Frame.__init__(self)
        self.master.geometry("400x300")
        self.master.title(" Ping játék")
        
        self.mbar = MenuBar(self)
        self.mbar.pack(side =TOP, expand =NO, fill =X)
        
        self.game =JatekTabla(self)
        self.game.pack(expand =YES, fill=BOTH, padx =8, pady =8)
        
        self.pack()
        
    def options(self):
        "A racs sor es oszlopszamanak kivalasztasa"
        opt =Toplevel(self)
        curL =Scale(opt, length =200, label ="Sorok száma :",
              orient =HORIZONTAL,
              from_ =1, to =12, command =self.majLignes)
        curL.set(self.game.nrow)     # a cursor kezdo pozicioja 
        curL.pack()
        curH =Scale(opt, length =200, label ="Oszlopok száma :",
              orient =HORIZONTAL,        
              from_ =1, to =12, command =self.majColonnes)
        curH.set(self.game.ncol)      
        curH.pack()
    
    def majColonnes(self, n):
        self.game.ncol = int(n)
        self.game.drawGrid()
    
    def majLignes(self, n):
        self.game.nrow = int(n)      
        self.game.drawGrid()

    def reset(self):
        self.game.initGame()
        self.game.drawGrid()
        
    def principe(self):
        "A játék elvét tartalmazó üzenetablak" 
        msg =Toplevel(self)
        Message(msg, bg ="navy", fg ="ivory", width =400,
            font ="Helvetica 10 bold", 
            text ="A minden korongnak van egy fehér és egy fekete oldala "\
            "Amikor egy korongra kattintunk, a 8 szomszédja átfordul\n"\
            "A játék abból áll, hogy megpróbáljuk mindet átfordítani.\n\n"\
            "Ha a gyakorlat 2 x 2-es ráccsal nagyon egyszerűnek tűnik, "\
            "nehezebbé válik nagyobb méretű rácsokkal. Sőt bizonyos "\
            "méretű rácsokkal egyáltalán nem lehet lejátszani.!\n\n "\
            "").pack(padx =10, pady =10)        

    def aPropos(self):
        "A szerzőt és a licenc típusát megadó üzenetablak" 
        msg =Toplevel(self)
        Message(msg, width =200, aspect =100, justify =CENTER,
            text ="Ping Játék").pack(padx =10, pady =10)
        
if __name__ == '__main__':
    Ping().mainloop()
	
#Panneau -> JatekTabla
#initJeu -> initGame
#etat -> state
#traceGrille -> drawGrid
#cote -> side
#larg -> width_
#haut -> height_
#coul .> color
#nlig -> nrow
#jeu -> game
