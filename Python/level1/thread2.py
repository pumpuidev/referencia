#! /usr/bin/python
# -*- coding: utf-8 -*-
import threading

class TestThread(threading.Thread):

   def run(self):

      print 'Hello, my name is', self.getName()

egy = TestThread()
egy.setName( 'Egyes' )
egy.start()

ketto = TestThread()
ketto.setName( 'Kettes' )
ketto.start()

TestThread().start()
