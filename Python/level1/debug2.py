import pdb

pdb.set_trace()
for i in [1,2,3,4,5,6,7,8]:
      j = i
      print i 
print spam

#print
#b(reak)
#j(ump)
#enable
#disable
#cl(ear)


# python debug2.py
#> /home/matej/scny/2014/ea9/debug2.py(4)<module>()
#-> for i in [1,2,3,4,5,6,7,8]:
#(Pdb) n
#> /home/matej/scny/2014/ea9/debug2.py(5)<module>()
#-> j = i

#(Pdb) print i
#1

#(Pdb) print j
#*** NameError: name 'j' is not defined

#(Pdb) n
#> /home/matej/scny/2014/ea9/debug2.py(6)<module>()
#-> print i

#(Pdb) print i
#1

#(Pdb) print j
#1

#(Pdb) b 5
#Breakpoint 1 at /home/matej/scny/2014/ea9/debug2.py:5

#(Pdb) b 6
#Breakpoint 2 at /home/matej/scny/2014/ea9/debug2.py:6

#(Pdb) c
#1
#> /home/matej/scny/2014/ea9/debug2.py(5)<module>()
#-> j = i

#(Pdb) c
#> /home/matej/scny/2014/ea9/debug2.py(6)<module>()
#-> print i

#(Pdb) disable 2

#(Pdb) c
#2
#> /home/matej/scny/2014/ea9/debug2.py(5)<module>()
#-> j = i

#(Pdb) enable 2

#(Pdb) c
#> /home/matej/scny/2014/ea9/debug2.py(6)<module>()
#-> print i

#(Pdb) cl 6
#No breakpoint numbered 6

#(Pdb) cl 2
#Deleted breakpoint 2

#(Pdb) c
#3
#> /home/matej/scny/2014/ea9/debug2.py(5)<module>()
#-> j = i

#(Pdb) j 6
#> /home/matej/scny/2014/ea9/debug2.py(6)<module>()
#-> print i

#(Pdb) print i
#4

#(Pdb) j 3
#> /home/matej/scny/2014/ea9/debug2.py(3)<module>()
#-> pdb.set_trace()

#(Pdb) print i
#4

#(Pdb) q
#Traceback (most recent call last):
  #File "debug2.py", line 3, in <module>
    #pdb.set_trace()
  #File "debug2.py", line 3, in <module>
    #pdb.set_trace()
  #File "/usr/lib/python2.7/bdb.py", line 48, in trace_dispatch
    #return self.dispatch_line(frame)
  #File "/usr/lib/python2.7/bdb.py", line 67, in dispatch_line
    #if self.quitting: raise BdbQuit
#bdb.BdbQuit

