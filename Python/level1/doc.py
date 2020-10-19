"""
This example module shows various types of documentation available for use
with pydoc.  To generate HTML documentation for this module issue the
command:

    pydoc -w doc

"""

class Example_Class(object):
    """
    Example_Class for illustrating documentation possibilities
    """
    def __init__(self, name, age):
        """
        Construct a new object.
        """
        self.name = name
        self.age = age
        
    def birthday(self):
        "Modifying the age field."
        self.age += 1    

def example_function(param):
    """
    Prints square of param to the display.
    """
    print param*param

if __name__ == '__main__':
    ex_ob = Example_Class('Kiss Tibor', 32)
    ex_ob.birthday()
    example_function(ex_ob.age)


# Try: 
#
#      pydoc doc
#      
#      python
#      >>> help('doc')
#
#      pydoc -w doc
#      pydoc -p 5000



