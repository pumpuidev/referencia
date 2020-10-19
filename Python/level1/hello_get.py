#!/usr/bin/python
# -*- coding: ISO-8859-2 -*-

# Hívás, pl.: http://127.0.0.1/cgi-bin/hello_get.py?first_name=Kis&last_name=Péter

# Import module for CGI handling 
import cgi 

# Create instance of FieldStorage 
form = cgi.FieldStorage() 

# Get data from fields
first_name = form.getvalue('first_name')
last_name  = form.getvalue('last_name')

print "Content-type:text/html\n\n"
print "<html>"
print "<head>"
print "<title>CGI Program</title>"
print "</head>"
print "<body>"
if first_name and last_name :
   print "<h2>Hello %s %s!</h2>" % (first_name, last_name)
else:
   print "<h2>Please enter 'First Name' and 'Last Name'!</h2>"    
print "</body>"
print "</html>"
