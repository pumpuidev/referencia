import sys

if len(sys.argv) >= 3 : 

    x = int(sys.argv[1])
    y = int(sys.argv[2])

    if (x > 0) and (y > 0) :
        while not (x == y) :
            if x > y :
                x = x - y
            else :
                y = y - x

        print x
    else: print "Tul kis parameterek!";
else:
    print "Keves a parameter!"
