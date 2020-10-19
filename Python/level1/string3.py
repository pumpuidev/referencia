#! /usr/bin/python

#   String muveletek

print ";".join("almafa")
# a;l;m;a;f;a

print "; ".join(["alma","korte","barack"])
# alma; korte; barack

print "		\n almafa  ".lstrip()
# almafa

print "ab..bacfre".lstrip("ba.")
# cfre

print "   almafa 	\n ".rstrip()
#    almafa

print "almac.*fg".rstrip("*cgf")
# almac.

print " \n  almafa 	\n ".strip()
# almafa

print "www.almafa.com".strip("w.mco")
# almafa

print "almafakortefaalatt".partition("fa")
# ('alma', 'fa', 'kortefaalatt')

print "almafaalatt".partition("ag")
# ('almafaalatt', '', '')

print "almafakortefaalatt".rpartition("fa")
# ('almafakorte', 'fa', 'alatt')

print "almafaalatt".replace("al", "*")
# *mafa*att

print "almafaalatt".replace("a", "**", 3)
# **lm**f**alatt







