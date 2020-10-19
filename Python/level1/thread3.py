#! /usr/bin/python
# -*- coding: utf-8 -*-
import threading
import time


class TestThread(threading.Thread):

   def run(self):

      print 'Futok még? (' + self.getName() + ')\n'
      time.sleep(.5)

class AnotherThread(TestThread):

   def run(self):
      
      print 'Futok még? (' + self.getName() + ')\n'
      time.sleep(3)
      
egyes = TestThread()
egyes.start()
kettes = AnotherThread()
kettes.start()

def test ():
   if egyes.isAlive():
      print 'Egyes: Igen!'
   else:
      print 'Egyes: Már nem!'
      
   if kettes.isAlive():
      print 'Kettes: Igen!'
   else:
      print 'Kettes: Már nem!'   

test()
time.sleep(1)
test()

