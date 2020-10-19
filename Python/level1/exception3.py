#! /usr/bin/python

class MyError(Exception):
    pass

try:
    raise MyError, 23
except MyError, x: 
    print "Sajat hiba, kod:", x

#  Sajat hiba, kod: 23


class MyError2(Exception):
    def __init__(self, value):
        self.value = value

try:
   raise MyError2, 23
except MyError2 as e:
    print "Sajat hiba, kod:", e.value    

# Sajat hiba, kod: 23






















