
def fib(x) :
    "Az x. Fibonacci-szamot kiszamito fuggveny."
    a = 0
    b = 1

    if x <= 0 :
        b = 0
    elif x == 1 :
        pass
    else :
        for i in range(x-1) :
            b , a = a+b, b         
    print "Az", x, ". Fibonacci-szam:"
    print b
    return b   

n = input("Irj be egy szamot: ")
x = fib(n)
print x
print fib.__doc__
