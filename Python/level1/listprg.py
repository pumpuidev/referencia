#! /usr/bin/python
import sys

print reduce(max, [2, 1, 4, 5, 21, 12, 34, 57, 2, 4, 6, 8])

# -----------------------

y = int(sys.argv[1])

# -----------------------

print filter(lambda x : y % x == 0, range(1,y+1))

# -----------------------

def f((x, pr), z) :
    if x%z == 0 :
        pr.append(z)
        return f((x/z, pr), z)
    else:
        return (x,pr)

prim  = [] 
p=reduce(f, range(2,y+1), (y,prim))
print p[1]


#f((10,[]),2) = f((5,[2]),2) = (5,[2])
#f((20,[]),2) = f((10,[2]),2) = f((5,[2,2]),2) = (5,[2,2])



# -------------------------------




















