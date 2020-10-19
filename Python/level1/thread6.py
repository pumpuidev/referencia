#! /usr/bin/python
# -*- coding: utf-8 -*-
import threading
import time

class ThreadLock(threading.Thread):

   def run(self):

      print 'Thread', self.getName(), 'started.'
      with lock: 
        print 'This part is critical! (' + self.getName() + ')'
        time.sleep(2)
        print 'Thread', self.getName(), 'ended.'
      
lock = threading.Lock()
egyes = ThreadLock()
egyes.start()
kettes = ThreadLock()
kettes.start()
harmas = ThreadLock()
harmas.start()
