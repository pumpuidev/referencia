#! /usr/bin/env python
# -*- coding: utf-8 -*-

def pascal(list) :
    tmp = [1,1]
    i = len(list) + 1
    for j in range(1, i-1) :
       tmp.insert(j, list[j-1] + list[j])
    return tmp


if __name__ == "__main__":
    print "Hány sort szeretnél?"
    x = input()
    list = [1]
    print list
    for i in range(1, x+1):
        list = pascal(list)
        print list   

