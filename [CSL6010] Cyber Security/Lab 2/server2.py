import socket
import threading

IP = socket.gethostbyname(socket.gethostname())
PORT = 1234
ADDR = (IP, PORT)
SIZE = 1024
FORMAT = "utf-8"
DISCONNECT_MSG = "!DISCONNECT"

def handle_client(conn, addr):
    print('Got connection from', addr)
    connected = True
    while connected:
        msg = conn.recv(SIZE).decode(FORMAT)
        if msg == DISCONNECT_MSG:
            connected = False
        ret = str(eval(msg)).encode()
        conn.send(ret)

    conn.close()


server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("Socket created")
server.bind(ADDR)
print("Socket binded to", PORT)
server.listen()
print("Socket is listening")

while True:
    conn, addr = server.accept()
    thread = threading.Thread(target=handle_client, args=(conn, addr))
    thread.start()
    print(f"Active Connections : {threading.activeCount() - 1}")
