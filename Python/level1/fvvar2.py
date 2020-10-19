# -*- coding: utf-8 -*-

x = "global_x"

def localfv2() :
    y = "fv2_y"
    
    def localfv3() :
        global x, y
        x, y = "fv3_x", "fv3_y"
    
    print "Az y értéke kezdetben:", y
    localfv3()    
    print "Az y értéke fv2 végén:", y

print "Az x értéke kezdetben:", x
localfv2()
print "Az x, y értéke végül:", x, y

# Az x értéke kezdetben: global_x
# Az y értéke kezdetben: fv2_y
# Az y értéke fv2 végén: fv2_y
# Az x, y értéke végül: fv3_x fv3_y
