#! /usr/bin/python
for i in [1,2,3] : 
    print i,
print ""
# 1 2 3

l = [1,2,3]
it = iter(l)
print it
# <listiterator object at 0x00CA7230>

print it.next()
# 1
print it.next()
# 2
print it.next()
# 3

# it.next()
# Traceback (most recent call last):
#   File "examples\ea3\iter.py", line 18, in <module>
#     it.next()
# StopIteration

class Pelda:
    "Pelda osztaly"
    def __init__(self, list1, list2):
        self.l1 = list1
        self.l2 = list2
        self.i  = 0
    def __iter__(self): 
        return self
    def next(self):
        if self.i < min(len(self.l1), len(self.l2) ) :
            self.i += 1
            return (self.l1[self.i-1], self.l2[self.i-1])
        else :
            raise StopIteration
            
pl = Pelda([1,2,3], "abcd")

for i in pl : print i;
# (1, 'a')
# (2, 'b')
# (3, 'c')


data = ['Peter', [1,2,3], 'Janos', [1,3,4], 'Miklos', [1,2,4]]

def get(x) :
    for i in range(0, len(x), 2) :
        yield (x[i], 3 in x[i+1])

print get(data)
#<generator object get at 0xb7843cd4>

for j in get(data) :
    print j

#('Peter', True)
#('Janos', True)
#('Miklos', False)









