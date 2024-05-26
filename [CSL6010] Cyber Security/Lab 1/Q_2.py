import socket
import sys
 
try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print ("Socket successfully created")
except socket.error as err:
    print ("socket creation failed with error %s" %(err))

port_number = 80
 
try:
    host_ip = socket.gethostbyname('www.iitj.ac.in')
except socket.gaierror:
    print ("Invalid host name")
    sys.exit()
 
s.connect((host_ip, port_number))
 
print ("connnected to https:://iitj.ac.in/")