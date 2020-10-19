#! /usr/bin/python
# -*- coding: utf8 -*-

class A():
    "Classic class"
    x = 1
    y = 1
    
class B(A):
    y = 2
    
class C(A):
    x = 3
    y = 3
    
class D(B,C):
    pass
    
d = D()
print d.x
# 1
print d.y    
# 2

# print D.__mro__
# AttributeError: class D has no attribute '__mro__'

# -------------------------------------------
# -------------------------------------------

class A(object):   # A, object
    "New-style class"
    x = 1
    y = 1
    
class B(A):    # B, A, object
    y = 2
    
class C(A):    # C, A, object
    x = 3
    y = 3
    
class D(B,C): # D, B, C, A, object 
    pass

d = D()
print d.x
# 3
print d.y    
# 2

print D.__mro__  # Method Resolution Order
# (<class '__main__.D'>, <class '__main__.B'>, 
# <class '__main__.C'>, <class '__main__.A'>, <type 'object'>)


# -------------------------------------------
# -------------------------------------------

class A(object):
    "New-style class"
    x = 1
    y = 1
    
class B(A):
    y = 2
    
class C(A):
    x = 3
    y = 3
    
class D(B,C):
    x = B.x

d = D()
print d.x
# 1
print d.y    
# 2

# -------------------------------------------
# -------------------------------------------


class A():
    "Classic class"
    x = 1
    y = 1
    
class B(A):
    y = 2
    
class C(object,A):
    x = 3
    y = 3
    
class D(B,C):
    pass
    
d = D()
print d.x
# 3
print d.y    
# 2

print D.__mro__ 
#(<class '__main__.D'>, <class __main__.B at 0x7f04b36b7ef0>, 
#<class '__main__.C'>, <type 'object'>, <class __main__.A at 0x7f04b36b7f58>)


# -------------------------------------------
# -------------------------------------------

class A():
    "Classic class"
    x = 1
    y = 1
    
class B(A):
    y = 2
    
class C(int,A):
    x = 3
    y = 3
    
class D(B,C):
    pass
    
d = D()
print d.x
# 3
print d.y    
# 2

# -------------------------------------------
# -------------------------------------------

O = object
class F(O): pass       # F, O
class E(O): pass       # E, O 
class D(O): pass       # D, O  
class C(D,F): pass     # C, D, F, O
class B(D,E): pass     # B, D, E, O
class A(B,C): pass     # A, B, C, D, E, F, O

print A.mro()
# [<class '__main__.A'>, <class '__main__.B'>, <class '__main__.C'>, 
# <class '__main__.D'>, <class '__main__.E'>, <class '__main__.F'>, 
# <type 'object'>]

# A szülők öröklési lánca ne sérüljön


#---------------------------


O = object
class F(O): pass      # F, O
class E(O): pass      # E, O
class D(O): pass      # D, O
class C(D,F): pass    # C, D, F, O
class B(E,D): pass    # B, E, D, O
class A(B,C): pass    # A, B, E, C, D, F, O

print A.mro()
# [<class '__main__.A'>, <class '__main__.B'>, <class '__main__.E'>, 
# <class '__main__.C'>, <class '__main__.D'>, <class '__main__.F'>, 
# <type 'object'>]


#---------------------------

O = object
class A(O): pass       # A, O
class B(O): pass       # B, O
class X(A, B): pass    # X, A, B, O
class Y(B, A): pass    # Y, B, A, O

#class Z(X, Y): pass

#Traceback (most recent call last):
# File "osztaly_prb.py", line 25, in <module>
#   class Z(X, Y): pass
#TypeError: Error when calling the metaclass bases
#    Cannot create a consistent method resolution
#order (MRO) for bases B, A




