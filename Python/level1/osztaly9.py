#! /usr/bin/python
# -*- coding: iso-8859-2 -*-

class A(object):
    def __getattr__(self,name):   # Csak akkor fut le, ha nincs beállított érték.
        if name == "x":
            return 40
        else:
            return None
            
    def __setattr__(self,name,value):
        if name == "x": 
             if value < 0 :
                 self.__dict__[name] = 0
             else:
                 self.__dict__[name] = value 
        else: print "Nem jó változó!"            
            
a = A()
print a.x
# 40
a.x = -10
print a.x
# 0
a.x = 10
print a.x
# 10
a.y = 15
# Nem jó változó!


# --------------------------------------------------------


class A(object):
    def __getattribute__(self,name): # Mindig ez fut le.
        if name == "x":
            return 40
        else:
            return None    
            
a = A()
print a.x
# 40
print a.y            
# None
a.x = 10
print a.x
# 40




# -------------------------

class A(object):
    def getx(self) :
        return 40
        
    def setx(self, value):
        if value < 0 :
           self._x = 0
        else:
           self._x = value 
            
    x = property(getx, setx)

a = A()
print a.x
# 40
a.x = -10
print a._x
# 0
a.x = 10
print a._x
# 10
print a.x
# 40


# -------------------------


class A(object):
    def getx(self) :
        ret = self._x
        if ret == 0 : return None
        else: return ret
        
    def setx(self, value):
        if value < 0 :
           self._x = 0
        else:
           self._x = value 
           
    def delx(self):
        del self._x
        
    x = property(getx, setx, delx)
        

a = A()
a.x = -10
print a.x
# None
a.x = 10
print a.x
# 10
del(a.x)
#print a.x
#
#Traceback (most recent call last):
#  File "osztaly9.py", line 110, in <module>
#    print a.x
#  File "osztaly9.py", line 86, in getx
#    ret = self._x
#AttributeError: 'A' object has no attribute '_x'


# -------------------------

class A(object):
    def getx(self) :  # Mindig ez fut le.
        return 40
        
    def setx(self, value):
        self.__dict__["x"] = value
            
    x = property(getx, setx)

a = A()
print a.x
# 40
a.x = 10
print a.x
# 40
