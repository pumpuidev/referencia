#! /usr/bin/python
import fv

# Ez meg a fv modulbol lefut!

x = 10
print "Ez mar a", __name__, "modul!"
print dir()
#Ez mar a __main__ modul!
#['__builtins__', '__doc__', '__file__', '__name__', 
#'__package__', 'fv', 'x']

print fv.f15()
# 15

fv.x = 20
print fv.f15()
# 20

fv.y = 56

reload(fv)
# Ez meg a fv modulbol lefut!

print fv.f15()
# 15

print dir(fv)
# ['__builtins__', '__doc__', '__file__', '__name__', '__package__', 'f10', 'f15', 'x', 'y']
