#! /usr/bin/python


try:
    raise NameError, "error"
finally:
    print "Ez mindenkepp kiirodik!"
 
#Ez mindenkepp kiirodik!
#Traceback (most recent call last):
#   File "examples\ea2\exception3.py", line 26, in <module>
#     raise NameError, "error"
#NameError: error



class MyError2(Exception):
    def __init__(self, value):
        self.value = value

try:
    pass
finally:
    print "Ez mindenkepp kiirodik!"

# Ez mindenkepp kiirodik!


try:
   raise MyError2, 23
except MyError2 as e:
    print "Sajat hiba, kod:", e.value 
finally:
    print "Ez mindenkepp kiirodik!"

# Sajat hiba, kod: 23
# Ez mindenkepp kiirodik!
