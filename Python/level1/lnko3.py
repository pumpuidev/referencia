x = input("Irj be egy szamot:")
y = input("Irj be egy ujabb szamot:")

while not (x == y) :
    if x > y :
        x = x - y
    else :
        y = y - x
        
print "A ket szam legnagyobb kozos osztoja:"
print x     
