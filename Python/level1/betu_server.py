#! /usr/bin/python
# -*- coding: utf-8 -*-

# simple illustration of threading module

# multiple clients connect to server; each client repeatedly sends a
# value k, which the server adds to a global string v and echos back
# to the client; k = ’’ means the client is dropping out; when all
# clients are gone, server prints final value of v

# this is the server

import socket # networking module
import sys
import threading

# class for threads, subclassed from threading.Thread class
class srvr(threading.Thread):
   # v and vlock are now class variables
   v = ''
   vlock = threading.Lock()
   id = 0 # I want to give an ID number to each thread, starting at 0
   
   def __init__(self,clntsock):
      # invoke constructor of parent class
      threading.Thread.__init__(self)
      
      # add instance variables
      self.myid = srvr.id
      srvr.id += 1
      self.myclntsock = clntsock
      
   
   def run(self):
      while 1:
         # receive letter from client, if it is still connected
         k = self.myclntsock.recv(1024)
         if k == '': break
         
         # update v in an atomic manner
         srvr.vlock.acquire()
         srvr.v += k
         srvr.vlock.release()
         
         # send new v back to client
         self.myclntsock.send(srvr.v)
         
      self.myclntsock.close()

# set up Internet TCP socket
lstn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
port = int(sys.argv[1]) # server port number

# bind lstn socket to this port
lstn.bind(('localhost', port))

# start listening for contacts from clients (at most 5 at a time)
lstn.listen(5)

nclnt = int(sys.argv[2]) # number of clients

mythreads = [] # list of all the threads

# accept calls from the clients
for i in range(nclnt):
   # wait for call, then get a new socket to use for this client,
   # and get the client’s address/port tuple (though not used)
   (clnt,ap) = lstn.accept()

   # make a new instance of the class srvr
   s = srvr(clnt)
 
   # keep a list all threads
   mythreads.append(s)
   
   # threading.Thread.start calls threading.Thread.run(), which we
   # overrode in our definition of the class srvr
   s.start()

# shut down the server socket, since it’s not needed anymore
lstn.close()

# wait for all threads to finish
for s in mythreads:
   s.join()

print 'the final value of v is', srvr.v
