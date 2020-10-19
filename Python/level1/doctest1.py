#! /usr/bin/env python
# -*- coding: utf-8 -*-

def osztoi(x):
    """
     Osztók kiszámítása.
    
    Minta:
    
    >>> osztoi(3)
    [1, 3]
    >>> osztoi(10)
    [1, 2, 5, 10]
    >>> osztoi(1)
    [1]
    >>> osztoi(a)
    Traceback (most recent call last):
      File "<stdin>", line 1, in <module>
    NameError: name 'a' is not defined

    """

    osztok=[1,x]
    temp=[]
    for i in range(2,(x/2)+1) :
        if x % i == 0 :
            temp += [i]
    osztok[1:1] = temp
    return osztok


    
if __name__ == "__main__":
    import doctest
    doctest.testmod()

# python doctest1.py

# python doctest1.py -v 


