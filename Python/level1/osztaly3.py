#! /usr/bin/python
      
class Auto:
    "Auto osztaly."
    def __init__(self, s):
        self.sebesseg = s
    def gyorsit(self, ds):
        self.sebesseg += ds
    def lassit(self, ds):
        self. sebesseg -= ds

class SzallitoJarmu:
    "Szallito osztaly."
    def __init__(self, x):
        self.szallitottszemelyek = x 
    def beszall(self, dx): 
        self.szallitottszemelyek  += dx
    def kiszall(self, dx): 
        self.szallitottszemelyek  -= dx    


class Busz(Auto, SzallitoJarmu):
    "Busz osztaly."
    def __init__(self, s, x):
        Auto.__init__(self, s)
        SzallitoJarmu.__init__(self, x)
        

b = Busz(30, 5)
b.gyorsit(10)
b.beszall(5)

print "A busz sebessege:", b.sebesseg, "km/h, utasainak szama:", b.szallitottszemelyek
# A busz sebessege: 40 km/h, utasainak szama: 10


class Os1:
    def __init__(self, x):
        self.x = x
    def plusz(self,dx):
        self.x +=dx

class Os2:
    def __init__(self, y):
        self.y = y
    def plusz(self,dy):
        self.y +=dy
    def minusz(self,dy):
        self.y -=dy

class Gyerek (Os1, Os2):
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def eltol(self,dx, dy):
        self.x  += dx
        self.y  += dy

gy = Gyerek(10,12)
gy.plusz(10)
gy.minusz(2)
print "x:", gy.x, "y:", gy.y
# x: 20 y: 10
