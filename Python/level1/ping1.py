#! /usr/bin/python
# -*- coding: utf-8 -*-
import os
import re
import time
import sys
import subprocess

lifeline = re.compile(r"(\d) received")
report = ("No response","Partial Response","Alive")

print time.ctime()

for host in range(45,55):
   ip = "157.181.161."+str(host)
   pingaling = subprocess.Popen("ping -q -c2 "+ip, 
                    shell = True, stdout=subprocess.PIPE ).stdout
   print "Testing ",ip,
   sys.stdout.flush()
   while 1:
      line = pingaling.readline()
      if not line: break
      igot = re.findall(lifeline,line)
      if igot:
           print report[int(igot[0])]

print time.ctime()
