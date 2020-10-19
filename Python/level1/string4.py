#! /usr/bin/python

import string
#   String muveletek

print "alma 	fa\nalatt\n".split()
# ['alma', 'fa', 'alatt']

print "".split()
# []

print "alma,,fa,alatt,".split(",")
# ['alma', '', 'fa', 'alatt', '']

print "".split(";")
# ['']

print "alma;fa;alatt".split(";", 1)
# ['alma', 'fa;alatt']

print "alma 	fa\nalatt\n".split(None, 1)
# ['alma', 'fa\nalatt\n']

print "alma;fa;alatt".rsplit(";", 1)   
# ['alma;fa', 'alatt']

print "alma 	fa\nalatt\n".rsplit(None, 1)
# ['alma \tfa', 'alatt']

print "alma\nfa\nalatt\n".splitlines()
# ['alma', 'fa', 'alatt']

print "alma\nfa\nalatt\n".splitlines(True)
# ['alma\n', 'fa\n', 'alatt\n']

print "almafaalatt".translate(None,"al")
# mftt

print "almafaalatt".translate(string.maketrans("atl","efk"), "l")
# emefeeeff

# --------------------

f = open("str_adatok2.txt", "r")
f2 = open("str_mail.txt", "w")
f3 = open("str_tel.txt", "w")

for line in f:
    tags = line.split()
    mailtags = tags[0:2] + [tags[2].replace("@","_at_"),"\n"] 
    f2.write(" ".join(mailtags))
    teltags = tags[0:2] + [tags[3].replace("-",""),"\n"]
    f3.write(" ".join(teltags))








