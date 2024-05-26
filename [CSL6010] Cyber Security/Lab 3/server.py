import socket            
import random   
s = socket.socket()        
print ("Socket successfully created")

port = 12345               
n = 1203
g = 647
j = random.randint(1, 1000)

sendData = str((g^j)%n)
s.bind(('', port))        
print ("socket binded to %s" %(port))
 
s.listen(5)    
# print ("socket is listening")           
 
while True:
  c, addr = s.accept()    
  print ('Got connection from', addr )
 
  c.send('connection established(sent from server)'.encode())
  recievedData = int(c.recv(1024).decode())
  secretKey = (recievedData^j)%n

  c.send(sendData.encode())
  print(sendData, "g^j sent to client by server (j is kept secret)")
  print(secretKey, "secret key on client side")

  c.close()
  break