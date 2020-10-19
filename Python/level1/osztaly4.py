#! /usr/bin/python

class Sz1:
    def kiir(self) :
        print self.x

class Sz2:
    x = 12

class Gyerek(Sz1, Sz2):
    z = 3
 
gy = Gyerek()
gy.kiir()
# 12 

# --------------------------------

class Nagyszulo:
    def __init__(self, x):
        self.x = x
    def plusz(self,dx):
        self.x +=dx

class Szulo1(Nagyszulo):
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def eltol(self, dx, dy):
        self.x  += dx
        self.y  += dy

class Szulo2:
    def __init__(self, z):
        self.z = z
    def plusz(self,dz):
        self.z +=dz
    def minusz(self,dz):
        self.z -=dz

class Gyerek(Szulo1, Szulo2):
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
    def eltol(self, dx, dy, dz):
        self.x  += dx
        self.y  += dy
        self.z  += dz
        
        
gy = Gyerek(0,0,0)
gy.plusz(10)
gy.minusz(5)
print "x:", gy.x, "y:", gy.y, "z:", gy.z
# x: 10 y: 0 z: -5

gy.eltol(1,2,3)
print "x:", gy.x, "y:", gy.y, "z:", gy.z
# x: 11 y: 2 z: -2

#gy.eltol(10,20)
#
#Traceback (most recent call last):
#  File "osztaly4.py", line 62, in <module>
#    gy.eltol(10,20)
#TypeError: eltol() takes exactly 4 arguments (3 given)


#NSz 
  #plusz (a)
#SZ1
#Sz2(NSz)
  #plusz (b)
#GY(SZ1, SZ2)
  #--- plusz  (b) 
  
#NSz 
  #plusz (a)
#SZ1(NSZ)
#Sz2(NSz)
  #plusz (b)
#GY(SZ1, SZ2)
  #--- plusz  (?) -- (a) -- classic style
                    #(b) -- new style   







