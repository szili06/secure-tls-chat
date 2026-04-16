//
// Created by szili on 4/16/26.
//

#include <unistd.h>
#include <openssl/ssl.h>

#include "network.h"
#include "chat_io.h"

int main() {
    SSL *ssl = connect_to_server("127.0.0.1", 8080);
    if (ssl == NULL) {
        return -1;
    }
    send_message(ssl, "Hello from C!");
    receive_message(ssl);
    SSL_shutdown(ssl);
    int fd = SSL_get_fd(ssl);
    close(fd);
    return 0;
}