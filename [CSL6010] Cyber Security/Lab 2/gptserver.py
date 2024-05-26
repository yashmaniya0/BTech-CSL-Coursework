import socket
import re

def evaluate_expression(expression):
    try:
        return str(eval(expression))
    except:
        return "Error: Invalid expression"

def start_server():
    host = '127.0.0.1'
    port = 12345

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(1)
    print("Server started at {}:{}".format(host, port))

    while True:
        client_socket, client_address = server_socket.accept()
        print("Accepted connection from {}:{}".format(client_address[0], client_address[1]))
        client_socket.send("Connected to server. Enter an expression:".encode())
        while True:
            expression = client_socket.recv(1024).decode()
            if not expression:
                break
            result = evaluate_expression(expression)
            client_socket.send(result.encode())
        client_socket.close()
        print("Closed connection from {}:{}".format(client_address[0], client_address[1]))

if __name__ == '__main__':
    start_server()
