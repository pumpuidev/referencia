#! /usr/bin/python

# szotar adatszerkezet

tel = {'Peter': 1234, 'Janos': 3456, 'Miklos': 2341}
print tel['Peter']
# 1234

tel['Janos'] = 1287
print tel
# {'Miklos': 2341, 'Peter': 1234, 'Janos': 1287}

del tel['Peter']
print tel
# {'Miklos': 2341, 'Janos': 1287}

tel['Jozsef'] = 65432
print tel
# {'Miklos': 2341, 'Janos': 1287, 'Jozsef': 65432}

print tel.keys()
# ['Miklos', 'Janos', 'Jozsef']

print tel.has_key('Janos')
#True

print tel.has_key('Geza')
#False

print dict([('a',2),('b',3),('c',42)])
# {'a': 2, 'c': 42, 'b': 3}

print dict([('a',2),('b',3),('c',42), ('a',43),('b',12)])
# {'a': 43, 'c': 42, 'b': 12}

print dict([(x,x**3) for x in [1,2,3] ])
# {1: 1, 2: 8, 3: 27}

def fv(x, y="egy", *args, **keyargs) :
    print "x:", x
    print "y:", y
    for arg in args: print arg;
    for kw in keyargs.keys(): print kw, ":", keyargs[kw]; 
    
fv(5, 12, 3, z=24, h=21)
#x: 5
#y: 12
#3
#h : 21
#z : 24

fv(5, z=24, h=21)
#x: 5
#y: egy
#h : 21
#z : 24

# fv(5,12,z=3,4)
#  File "<stdin>", line 1
# SyntaxError: non-keyword arg after keyword arg


tel = {'Peter': 1234, 'Janos': 3456, 'Miklos': 2341}
for k, v in tel.iteritems() :
    print k, "szama:", v

#Miklos szama: 2341
#Peter szama: 1234
#Janos szama: 3456

for i,v in enumerate(["a","b","c","d"]) :
    print i, v

#0 a
#1 b
#2 c
#3 d
   
