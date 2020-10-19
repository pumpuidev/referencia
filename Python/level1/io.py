#! /usr/bin/python
# 

for x in range(1,5) :
    print str(x).ljust(2),  # a vesszo miatt, ebben a sorban folytatodik
    print str(5*x).center(3),
    print str(x**x).rjust(3)
    
#1   5    1
#2   10   4
#3   15  27
#4   20 256


for x in range(1,5) :
    print "%2d %-2d %3d" %(x, 5*x, x**x)
 
# 1 5    1
# 2 10   4
# 3 15  27
# 4 20 256


print "Float:%8.3f" %(6.98767654) # osszesen 8 karakterre igazit, ponttal egyutt
#Float:   6.988

 
tel = {'Peter': 1234, 'Janos': 3456, 'Miklos': 2341}
print "Miklos: %(Miklos)6d, Peter: %(Peter)d, Janos: %(Janos)d" % tel
# Miklos:   2341, Peter: 1234, Janos: 3456

for x in range(1,5) :
    print "{0:2d} {1:<2d} {2:^3d}".format(x, 5*x, x**x)
 
# 1 5   1
# 2 10  4
# 3 15 27
# 4 20 256


tel = {'Peter': 1234, 'Janos': 3456, 'Miklos': 2341}
tel2 = {'Peter': 4567, 'Janos': 5634, 'Miklos': 1342}
print "Miklos: {0[Miklos]:d}, Peter: {0[Peter]:d}, Janos: {1[Janos]:d}".format(tel,tel2)
# Miklos: 2341, Peter: 1234, Janos: 5634

print "Miklos: {Miklos:d}, Peter: {Peter:d}, Janos: {Janos:d}".format(**tel)
# Miklos: 2341, Peter: 1234, Janos: 3456

print "Miklos: {Miklos:d}, Peter: {Peter:d}, Janos: {Janos:d}".format(Miklos=2341,Peter=1234,Janos=3456)
# Miklos: 2341, Peter: 1234, Janos: 3456


print "Irj be egy erteket!"
x = input()
print x + 4

print "Irj be egy stringet!"
x = raw_input()
print "A szoveg:", x 







