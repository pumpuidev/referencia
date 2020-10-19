
def mult(x) :
    return lambda n : x * n
    

double = mult(2)
triple = mult(3)

print double(8)
#16

print triple(8)
#24   
