#! /usr/bin/python
# -*- coding: utf-8 -*-
import os
import re
import time
import sys
from threading import Thread
import subprocess

class testit(Thread):
   def __init__ (self,ip):
      Thread.__init__(self)
      self.ip = ip
      self.status = -1
   def run(self):
      pingaling = subprocess.Popen("ping -q -c2 "+ip, 
                     shell = True, stdout=subprocess.PIPE ).stdout
      while 1:
        line = pingaling.readline()
        if not line: break
        igot = re.findall(testit.lifeline,line)
        if igot:
           self.status = int(igot[0])

testit.lifeline = re.compile(r"(\d) received")
report = ("No response","Partial Response","Alive")

print time.ctime()

pinglist = []

for host in range(45,55):
   ip = "157.181.161."+str(host)
   current = testit(ip)
   pinglist.append(current)
   current.start()

for pingle in pinglist:
   pingle.join()
   print "Status from ",pingle.ip,"is",report[pingle.status]

print time.ctime()
