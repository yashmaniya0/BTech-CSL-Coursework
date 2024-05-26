import socket

def start_client(server_ip, server_port):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((server_ip, server_port))
    print(client_socket.recv(1024).decode())
    while True:
        expression = input("Enter an expression: ")
        client_socket.send(expression.encode())
        result = client_socket.recv(1024).decode()
        print("Result: {}".format(result))

if __name__ == '__main__':
    server_ip = input("Enter server IP: ")
    server_port = int(input("Enter server port: "))
    start_client(server_ip, server_port)
