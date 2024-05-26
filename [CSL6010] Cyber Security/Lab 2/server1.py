# Single Process Server

import socket

s = socket.socket()
print("Socket created")

port = 12345

s.bind(('', port))
print("Socket binded to", port)

s.listen(5)
print("Socket is listening")

c, addr = s.accept()

while True:
    print('Got connection from', addr)
    data = c.recv(1024).decode()
    if data == 'close server':
        c.close()
    data = str(eval(data))
    if not data:
        c.close()
        break
    c.sendall(bytes(data, 'utf-8'))