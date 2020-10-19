#! /usr/bin/python

class C():
    "Classic class"
    pass 

class D(object):
    "New-style class (default in Python 3)"
    pass
    
x = C()
print type(x)
# <type 'instance'>
print x.__class__
#__main__.C

y = D()
print type(y)      
# <class '__main__.D'>
print y.__class__
# <class '__main__.D'>

class E():
    def __init__(self):
        self.x = 12
    
class F(object):
    pass
    
z = E()
w = F()

print type(x) == type(z)
# True

print type(y) == type(w)
# False






