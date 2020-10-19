import sys

x = int(sys.argv[1])
y = int(sys.argv[2])

while not (x == y) :
    if x > y :
        x = x - y
    else :
        y = y - x
        
print x        
