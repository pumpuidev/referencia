#! /usr/bin/python

from fv import *  # az "_"-al kezdodoeken kivul minden az fv modulbol

# Ez meg a fv modulbol lefut!

print dir()
#['__builtins__', '__doc__', '__file__', '__name__', '__package__',
# 'f10', 'f15', 'x']

print f10()
#10

print f15()
#15

print x
#15

x = 20
print f15()
# 15

print x
# 20

#print fv.f15()
# Traceback (most recent call last):
#   File "examples\ea3\imp3.py", line 14, in <module>
#     print fv.f15()
# NameError: name 'fv' is not defined


