#! /usr/bin/python

#   String muveletek

print "alma\tfa".expandtabs(4)
# "alma    fa"

print "almafaalatt".find("fa")
# 4

print "almafaalatt".find("korte")
# -1

print "abrakadabra".rfind("ra")
# 9

print "abrakadabra".rfind("fa")
# -1

print "	  	".isspace()
# True

print "12346756".isdigit()
# True

print "23 45 56".isdigit()
# False

# ------------------

f = open("str_adatok.txt", "r")
lines = f.readlines()
f.close()

notemptylines = filter(lambda x: not x.isspace(), lines)
newlines = map(lambda x: x.expandtabs(0), notemptylines)

f2 = open("str_kimenet.txt", "w")
for line in newlines:
    f2.write(line)
f2.close()

# -------------------

f = open("str_adatok.txt", "r")
f2 = open("str_kimenet2.txt", "w")

for line in [x.expandtabs(0) for x 
                in filter(lambda y: not y.isspace(),f.readlines() )]:
    f2.write(line)

f.close()
f2.close()

# -------------------

f = open("str_kimenet.txt", "r")

szamok = []
for line in f:
    szamok.append(line[line.rfind(" ")+1:-1]) # Windowson -2
f.close()
print szamok
# ['123-45678', '478-2356', '254-6752', '342-8765', '453-9876', '231-9834']






