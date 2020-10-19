#! /usr/bin/env python
# -*- coding: utf-8 -*-

def fv1(x,y) :  
    "Az első függvény'"
    

def fv2() :
    '"A második függvény"'

def fv3 (x) :
    """A harmadik "függvény"""

def fv4  (x,y,z) : 
    '''A negyedik ''függvény'''

def fv5() :
    '''Az ötödik ''
         ''függvény'''

def fv6(y, z = 5) : 'A hatodik függvény'

def fv7() : """A hetedik 
    "
    '''
    függvény"""


def fv8(x) : 

   
   'A nyolcadik függvény'
   
def fv9 () : 21;   
   

if __name__ == "__main__":
    print fv1.__doc__
    print fv2.__doc__    
    print fv3.__doc__
    print fv4.__doc__    
    print fv5.__doc__
    print fv6.__doc__
    print fv7.__doc__
    print fv8.__doc__
