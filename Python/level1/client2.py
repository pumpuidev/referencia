#! /usr/bin/python
# -*- coding: utf-8 -*-

# Client program

from socket import *

# Set the socket parameters
host = "localhost"
port = 21567
buf = 1024
addr = (host,port)

# Create socket
StreamSock = socket(AF_INET,SOCK_STREAM)

StreamSock.connect(addr)


def_msg = "===Enter message to send to server===";
print "\n",def_msg

# Send messages
while (1):
    data = raw_input('>> ')
    if not data:
        StreamSock.send('')
        break
    else:
        if(StreamSock.send(data)):
            print "Sending message '",data,"'....."

# Close socket
StreamSock.close()

