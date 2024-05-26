# Question 4

import socket

s = socket.socket()
print("Socket successfully created")

port = 12345

s.bind(('', port))
print("Socket binded to", port)

s.listen(5)
print("Socket is listening")

while True:

    c, addr = s.accept()
    print('Got connection from', addr)
    data = c.recv(1024).decode()
    data = data.upper()       # this is what converts the string to Capital Case

    if not data:
        break

    c.sendall(bytes(data, 'utf-8'))
    c.close()