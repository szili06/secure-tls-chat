
def handle_client(client_socket):
    string = client_socket.recv(1024).decode('UTF-8')
    print(string)
    message = "I got your message! - Python".encode('UTF-8')
    client_socket.sendall(message)
    client_socket.close()