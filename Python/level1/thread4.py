#! /usr/bin/python
# -*- coding: utf-8 -*-
import threading
import time

class ThreadOne(threading.Thread):

   def run(self):

      print 'Thread', self.getName(), 'started.'
      time.sleep(1)
      print 'Thread', self.getName(), 'ended.'

class ThreadTwo (threading.Thread):

   def run(self):

      print 'Thread', self.getName(), 'started.'
      egyes.join()
      #egyes.join(0.5)
      print 'Thread', self.getName(), 'ended.'

egyes = ThreadOne()
egyes.start()
kettes = ThreadTwo()
kettes.start()
