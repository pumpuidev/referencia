import sys

def lnko(x=10, y=15):
    "Ket szam legnagyobb kozos osztoja."
    print x, "es", y, "legnagyobb kozos osztoja:"
    while not (x == y) :
        if x > y :
            x = x - y
        else :
            y = y - x

    print x 

if len(sys.argv) >= 3 : 
    x = int(sys.argv[1])
    y = int(sys.argv[2])
    lnko(x,y)
elif len(sys.argv)== 2 :
    z = int(sys.argv[1])
    lnko(x=z)
    lnko(y=z)
    lnko(z)
else:
    lnko()
    
    
       
