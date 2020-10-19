#! /usr/bin/python

class A():
    x = 1
    y = 1
    
class B(A):
    y = 2
    
class C(A):
    x = 3
    y = 3
    z = 3
    
class D(B,C):
    pass
    
d = D()
print d.x
# 1
print d.y    
# 2
print d.z
# 3
