import socket             
import sys 

s = socket.socket()         
port = 12345      

try:
	s.connect(('127.0.0.1', port))
except socket.error as message:
    print('Bind failed. Error Code : ' + str(message[0]) + ' Message ' + message[1])
    sys.exit()

while True:
	input_string = input("Enter a something : ")
	s.sendall(input_string.encode())
	print("Message received :", s.recv(1024).decode())
