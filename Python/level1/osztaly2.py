#! /usr/bin/python

class Koordinata:
    "Koordinata osztaly."
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def eltol(self, dx, dy) : 
        self.x  += dx
        self.y  += dy
     

poz = Koordinata(5,2)
poz.eltol(4,3)
print "x:", poz.x, "y:", poz.y 
# x: 9 y: 5


class TerKoordinata(Koordinata):
     "Terkoordinata osztaly"
     def __init__(self, x, y, z):
         Koordinata.__init__(self, x, y)
         self.z = z
     def eltol3D(self, dx, dy, dz):
         self.eltol(dx,dy)
         self.z += dz


poz3D = TerKoordinata(5,2,4)
poz3D.eltol(4,3)
print "x:", poz3D.x, "y:", poz3D.y 
# x: 9 y: 5
poz3D.eltol3D(5,2,11)
print "x:", poz3D.x, "y:", poz3D.y, "z:", poz3D.z  
# x: 14 y: 7 z: 15

print isinstance(poz3D, Koordinata)
# True
print isinstance(poz3D, TerKoordinata)
# True

