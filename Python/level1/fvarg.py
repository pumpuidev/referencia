# -*- coding: utf-8 -*-

def tizenot() :
    return 15

print "tizenöt:", tizenot()

t15 = tizenot
print "t15:", t15()

# tizenöt: 15
# t15: 15

# -----------------------

x = 10
def fv(arg=x) :
    print "arg:", arg    

x = 20
fv()

#arg: 10

# ----------------------

list = [1,2,3]
def fv2(arg2=list) :
    print "arg2:", arg2    

list[1] = 4
fv2()

#arg2: [1, 4, 3]

# ----------------------

list = [1,2,3]
list2 = list
list[1] = 4

print list, list2

# [1, 4, 3] [1, 4, 3]

# ----------------------

def fv3(x,y) :
    print "osszeg:", x+y    

list = [5,8] 
fv3(*list)

#osszeg: 13

