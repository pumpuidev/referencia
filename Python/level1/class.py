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


class Os1 ():
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


class Nagyszulo:
    x = 42

class Szulo1(Nagyszulo):
    def kiir(self) :
        print self.x

class Szulo2:
    x = 12

class Gyerek(Szulo1, Szulo2):
    z = 3
    def kiir(self) :
        print self.x, self.z

gy = Gyerek()
gy.kiir()
# 42 3


class Sz1:
    def kiir(self) :
        print self.x

class Sz2:
    x = 12

class Gyerek(Sz1, Sz2):
    z = 3
    def kiir(self) :
        print self.x, self.z

gy = Gyerek()
gy.kiir()
# 12 3



class OsOs:
    def __init__(self,x):
        self.x = x
    def plusz(self,dx):
        self.x +=dx
    def minusz(self,dx):
        self.x -=dx

class Os1(OsOs):
    def __init__(self,x,y):
        self.x = x
        self.y = y
    def eltol(self, dx, dy):
        self.x  += dx
        self.y  += dy

class Os2(OsOs):
    def __init__(self,x,z):
        self.x = x
        self.z = z
    def plusz(self, dz):
        self.z += dz
    def eltol(self, dx, dz):
        self.x  += dx
        self.z  += dz

class Gyerek(Os1,Os2):
    def __init__(self, x, y, z):
        self.x = x
	self.y = y
        self.z = z

gy = Gyerek(0,0,0)
gy.plusz(10)
print "x:", gy.x, "y:", gy.y, "z:", gy.z
# x: 10 y: 0 z: 0

gy.eltol(2,4)
print "x:", gy.x, "y:", gy.y, "z:", gy.z
# x: 12 y: 4 z: 0
