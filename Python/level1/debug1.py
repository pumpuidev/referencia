import pdb

pdb.set_trace()
for i in [1,2,3,4]:
      j = i
      pdb.set_trace()
      print i 
print spam

#s(tep)
#n(ext)    ----  (The difference between next and step is that step stops inside a called function, while next executes called functions...)
#c(ont(inue))
#l(ist)
#w(here)
#u(p)
#d(own)

#h(elp)
#q(uit)

# python debug1.py
#> /home/matej/scny/2014/ea9/debug1.py(4)<module>()
#-> for i in [1,2,3,4]:
#(Pdb) n
#> /home/matej/scny/2014/ea9/debug1.py(5)<module>()
#-> j = i

#(Pdb) n
#> /home/matej/scny/2014/ea9/debug1.py(6)<module>()
#-> pdb.set_trace()

#(Pdb) n
#> /home/matej/scny/2014/ea9/debug1.py(7)<module>()
#-> print i

#(Pdb) n
#1
#> /home/matej/scny/2014/ea9/debug1.py(4)<module>()
#-> for i in [1,2,3,4]:

#(Pdb) s
#> /home/matej/scny/2014/ea9/debug1.py(5)<module>()
#-> j = i

#(Pdb) s
#> /home/matej/scny/2014/ea9/debug1.py(6)<module>()
#-> pdb.set_trace()

#(Pdb) s
#--Call--
#> /usr/lib/python2.7/pdb.py(1250)set_trace()
#-> def set_trace():

#(Pdb) s
#> /usr/lib/python2.7/pdb.py(1251)set_trace()
#-> Pdb().set_trace(sys._getframe().f_back)

#(Pdb) w
  #/home/matej/scny/2014/ea9/debug1.py(6)<module>()
#-> pdb.set_trace()
#> /usr/lib/python2.7/pdb.py(1251)set_trace()
#-> Pdb().set_trace(sys._getframe().f_back)

#(Pdb) n
#--Return--
#> /usr/lib/python2.7/pdb.py(1251)set_trace()->None
#-> Pdb().set_trace(sys._getframe().f_back)

#(Pdb) n
#> /home/matej/scny/2014/ea9/debug1.py(7)<module>()
#-> print i

#(Pdb) l
  #2  	
  #3  	pdb.set_trace()
  #4  	for i in [1,2,3,4]:
  #5  	      j = i
  #6  	      pdb.set_trace()
  #7  ->	      print i 
  #8  	print spam
  #9  	
 #10  	# python debug1.py
#[EOF]

#(Pdb) n
#2
#> /home/matej/scny/2014/ea9/debug1.py(4)<module>()
#-> for i in [1,2,3,4]:

#(Pdb) n
#> /home/matej/scny/2014/ea9/debug1.py(5)<module>()
#-> j = i

#(Pdb) n
#> /home/matej/scny/2014/ea9/debug1.py(6)<module>()
#-> pdb.set_trace()

#(Pdb) c
#> /home/matej/scny/2014/ea9/debug1.py(7)<module>()
#-> print i

#(Pdb) c
#3
#> /home/matej/scny/2014/ea9/debug1.py(6)<module>()
#-> pdb.set_trace()

#(Pdb) c
#4
#Traceback (most recent call last):
  #File "debug1.py", line 6, in <module>
    #pdb.set_trace()
#NameError: name 'spam' is not defined
