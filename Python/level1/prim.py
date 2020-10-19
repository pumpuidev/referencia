print "Irj be egy szamot:"
x = input()

print x, "primtenyezoi:"
prim=[]
i=2
y = x
while i <= y/2 :
    if x % i == 0 :
        prim += [i]   
        x = x/i
    else :
       i += 1

if prim == [] and x > 1 :
    prim = [x] 
print prim