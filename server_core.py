from config import HOST, PORT, BUFFER_SIZE
import socket
import message_handler
import ssl

ssl_context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
ssl_context.load_cert_chain(certfile="server.crt", keyfile="server.key")


server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server_socket.bind((HOST, PORT))
server_socket.listen(5)

secure_socket = ssl_context.wrap_socket(server_socket, server_side=True)

while True:
    client_socket, user_addr = secure_socket.accept()
    message_handler.handle_client(client_socket)