#! /usr/bin/python
# -*- coding: utf-8 -*-

# Server program

from socket import *

# Set the socket parameters
host = "localhost"
port = 21567
buf = 1024
addr = (host,port)

# Create socket and bind to address
StreamSock = socket(AF_INET,SOCK_STREAM) 
StreamSock.bind(addr)

StreamSock.listen(2)
(conn, addr2) = StreamSock.accept()


# Receive messages
while 1:
    data  = conn.recv(1024)
    if not data:
        print "Client has exited!"
        break
    else:
        print "\nReceived message '", data,"'"

# Close socket
StreamSock.close()
