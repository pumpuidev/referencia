#! /usr/bin/python
# -*- coding: utf-8 -*-
import threading
import time

class ThreadLock(threading.Thread):

   def run(self):

      print 'Thread', self.getName(), 'started.'
      with sem:
          print 'This part is critical! (' + self.getName() + ')'
          time.sleep(3)
          print 'Thread', self.getName(), 'ended.'
      

sem = threading.Semaphore(2)
egyes = ThreadLock()
egyes.start()
kettes = ThreadLock()
kettes.start()
harmas = ThreadLock()
harmas.start()
