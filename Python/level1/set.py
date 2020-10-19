#! /usr/bin/python

# Halmaz adatszerkezet

list = [2, 3, 1, 2, 4, 5, 6, 12, 3, 2, 1, 10] 
s = set(list)
print s
# set([1, 2, 3, 4, 5, 6, 10, 12])

print 10 in s
# True

print 11 in s
# False

s.add(15)
print s
#set([1, 2, 3, 4, 5, 6, 10, 12, 15])

s.discard(3)
print s
#set([1, 2, 4, 5, 6, 10, 12, 15])

print set("bcdeabcgh")
# set(['a', 'c', 'b', 'e', 'd', 'g', 'h'])

a = set([1, 2, 3, 4, 5, 6])
b = set([2, 3, 5, 4, 7, 8])
print a - b
# set([1, 6])

print a & b  # metszet
# set([2, 3, 4, 5])

print a | b  # unio
# set([1, 2, 3, 4, 5, 6, 7, 8])

print a ^ b  # xor  (a|b) - (a&b)
# set([1, 6, 7, 8])
