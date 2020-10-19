
"Example modul importing doc ... "

import doc

def fun2(param1,param2):
    " Function for using ob.birthday() function"
    ob = doc.Example_Class('Kiss Tibor', 32)  
    ob.birthday()
    print ob.age
    return ob
    

def fun3(ob):
    "Function for printing the age field"
    print ob.age    

    
myob = fun2("hkjhkj", 23)
fun3(myob)    
