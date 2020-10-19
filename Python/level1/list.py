#! /usr/bin/env python

# Lista adatszerkezet 

list = [0,1,2,3,4]

list.append(5)   # list[len(list):] = [5]
print list
# [0, 1, 2, 3, 4, 5]

list.extend([6,7,8])   # list[len(list):] = [6,7,8]
print list
# [0, 1, 2, 3, 4, 5, 6, 7, 8]

list.insert(4,"uj_elem") # adott indexu elem ele szur be
print list
# [0, 1, 2, 3, 'uj_elem', 4, 5, 6, 7, 8]
list.insert(42,"uj_elem")
print list
# [0, 1, 2, 3, 'uj_elem', 4, 5, 6, 7, 8, 'uj_elem']

list.remove("uj_elem")
print list
# [0, 1, 2, 3, 4, 5, 6, 7, 8, 'uj_elem']

#list.remove(12)
# ValueError: list.remove(x): x not in list


list = ['nulla','egy','ketto','harom']
x = list.pop(2)
print list, ",", x
# ['nulla', 'egy', 'harom'] , ketto

x = list.pop()
print list, ",", x
# ['nulla', 'egy'] , harom

#x = list.pop(42)
# IndexError: pop index out of range


stack = []
stack.append(1)
stack.append(2)
print stack
# [1, 2]

stack.pop()
print stack
# [1]


print list.index('egy')
# 1

#list.index("uj_elem")
#ValueError: list.index(x): x not in list

print [1,2,1,3,4,1].count(1)
# 3

list = [3,2,4,1,5,8,7] 
list.sort()
print list
# [1, 2, 3, 4, 5, 7, 8]

list.reverse()
print list
# [8, 7, 5, 4, 3, 2, 1]

print filter(lambda x: x%3==0, range(1,10))
# [3, 6, 9]

print map(lambda x: x**2, range(1,10))
# [1, 4, 9, 16, 25, 36, 49, 64, 81]

list = range(1,10)
print map(lambda x, y : x+y, list, list)
# [2, 4, 6, 8, 10, 12, 14, 16, 18]


def fv(x,y) : print x, y;

map(fv, range(1,3), range(1,5))
# 1 1
# 2 2
# None 3
# None 4

print map(None, range(1,10,2), range(2,11,2))
# [(1, 2), (3, 4), (5, 6), (7, 8), (9, 10)]

print reduce(lambda x, y : x+y, range(1,11))
# 55

print reduce(lambda x, y : x+y, range(1,11), 20)  # a-> b -> a, [b], a
# 75


print [x**2 for x in range(1,10)]
# [1, 4, 9, 16, 25, 36, 49, 64, 81]

print [x**2 for x in range(1,10) if x > 5]
# [36, 49, 64, 81]

print [x*y for x in [2,4] for y in [3,5]]
# [6, 10, 12, 20]

print [x*y for x, y in zip([2,4],[3,5])]
# [6, 20]

print zip([1,2,3],[5,6])
# [(1, 5), (2, 6)]



  +   [1,2,3,4,5 ... 10]
  
       1+2
        3+3
          6+ 4
            10+5
              ... 
              
              
  +    [1,2,3..10]   20
  
     20+1
       21+2
         23+3
            ...       
  
              
       


