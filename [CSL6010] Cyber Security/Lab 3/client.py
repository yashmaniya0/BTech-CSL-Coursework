import socket     
import random       
s = socket.socket()        
port = 12345               
 
n = 1203
g = 647
i = random.randint(1, 1000)
sendData = str((g^i)%n)

s.connect(('127.0.0.1', port))
recievedData = s.recv(1024).decode()
s.sendall(sendData.encode())
print(sendData, "g^i send to server by client (i is kept secret)")

recievedData = int(s.recv(1024).decode())

secretKey = (recievedData^i)%n
print(secretKey, "secret key on client side")

s.close()