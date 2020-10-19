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
UDPSock = socket(AF_INET,SOCK_DGRAM)
#AF_INET: IPv4 protocols (both TCP and UDP)
#AF_INET6: IPv6 protocols (both TCP and UDP)
#AF_UNIX: UNIX domain protocols 

#SOCK_STREAM: a connection-oriented, TCP byte stream
#SOCK_DGRAM: UDP transferral of datagrams (self-contained IP packets that do not rely on client-server confirmation)
#SOCK_RAW: a raw socket
#SOCK_RDM: for reliable datagrams
#SOCK_SEQPACKET: sequential transfer of records over a connection 

UDPSock.bind(addr)

# Receive messages
while 1:
    data,addr = UDPSock.recvfrom(buf)
    if not data:
        print "Client has exited!"
        break
    else:
        print "\nReceived message '", data,"'"

# Close socket
UDPSock.close()
