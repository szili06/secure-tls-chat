//
// Created by szili on 4/16/26.
//

#include "chat_io.h"
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <openssl/ssl.h>

void send_message(SSL *ssl, const char* message) {
    SSL_write(ssl, message, strlen(message));
}

void receive_message(SSL *ssl) {
    char buffer[1024];
    memset(buffer, 0, 1024);
    SSL_read(ssl, buffer, sizeof(buffer));
    printf("%s", buffer);
}