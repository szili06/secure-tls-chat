//
// Created by szili on 4/14/26.
//

#include "network.h"
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

SSL* connect_to_server(const char* ip_address, int port) {
    int called_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (called_socket < 0) {
        ERR_print_errors_fp(stderr);
        return NULL;
    }
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server_address.sin_addr);
    if (connect(called_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        ERR_print_errors_fp(stderr);
        return NULL;
    }
    SSL_CTX *context = SSL_CTX_new(TLS_client_method());
    SSL *secure_socket = SSL_new(context);
    SSL_set_fd(secure_socket, called_socket);
    if (SSL_connect(secure_socket) <= 0) {
        ERR_print_errors_fp(stderr);
        return NULL;
    }
    return secure_socket;
}