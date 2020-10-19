#! /usr/bin/python

import re

# Regularis kifejezesek

'.' # egy db barmilyen karakter, kiveve '\n', ha a 
    # re.DOTALL flag be van allitva '\n' is lehet

print re.match("a.m.", "almafa")
# <_sre.SRE_Match object at 0x00B9AA30>

print re.match("a.m.", "alm\nfa")
# None

print re.match("a.m.", "alm\nfa", re.DOTALL)
# <_sre.SRE_Match object at 0x00B9AA30>

print re.match("a.m.", "alm\nfa", re.S)
# <_sre.SRE_Match object at 0x00B9AA30>

r = re.compile("a.m.", re.S)
print r.match("alm\nfa")
# <_sre.SRE_Match object at 0x00B9AA30>

print re.match("f.", "almafa")
# None

print re.search("f.", "almafa")
# <_sre.SRE_Match object at 0x00B9AA30>

m = re.match("a.m.", "almafa")
print m.group()
# alma

print m.start()
# 0

print m.end()
# 4

print m.span()
# (0, 4)

m = re.search("f.", "almafa")
print m.group()
# fa

print m.span()
# (4, 6)














