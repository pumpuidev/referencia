#! /usr/bin/python
# -*- coding: iso-8859-2 -*-

class A():
    def __getattr__(self,name): # Csak akkor fut le, ha nincs beállított érték.
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
# 10

# --------------------------------------------------------


class A():
    def __getattr__(self,name):  # Csak akkor fut le, ha nincs beállított érték.
        if name == "x":
            return 40
        else:
            return None
            
    def __setattr__(self,name,value): # Mindig ez fut le.
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



#class A():
#    def __setattr__(self,name,value):
#        if name == "x": 
#             if value < 0 :
#                 self.x = 0
#             else:
#                 self.x = value 
#        else: print "Nem jó változó!"       

#a = A()
#a.x = -10
#print a.x

#  File "osztaly8.py", line 61, in __setattr__
#    self.x = value 
#  File "osztaly8.py", line 61, in __setattr__
#    self.x = value 
#  ...
#  ... 
#  File "osztaly8.py", line 61, in __setattr__
#    self.x = value 
#  RuntimeError: maximum recursion depth exceeded


# --------------------------------------------------------

class B(object):
    def __getattr__(self,name):  # Csak akkor fut le, ha nincs beállított érték.
        if name == "x":
            return 40
        else:
            return None
            
    def __setattr__(self,name,value): # Mindig ez fut le.
        if name == "x": 
             if value < 0 :
                 object.__setattr__(self, name, 0)
             else:
                 object.__setattr__(self, name, value)
        else: print "Nem jó változó!"            
            
b = B()
print b.x
# 40
b.x = -10
print b.x
# 0
b.x = 10
print b.x
# 10
b.y = 15
# Nem jó változó!



# --------------------------------------------------------



class C(object):
    def __getattribute__(self,name): # Mindig ez fut le.
        if name == "y":
            return 10
        else:
            return object. __getattribute__(self,name) + 10
            
    def __setattr__(self,name,value): # Mindig ez fut le.
        if name == "x": 
             if value < 0 :
                 object.__setattr__(self, name, 0)
             else:
                 object.__setattr__(self, name, value)
        else: print "Nem jó változó!"                 
            
c = C()
c.x = 10
print c.x
# 20
c.x = -10
print c.x
# 10
print c.y            
# 10
