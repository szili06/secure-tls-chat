//
// Created by szili on 4/16/26.
//

#ifndef CHAT_IO_H
#define CHAT_IO_H

#include <openssl/ssl.h>

void send_message(SSL *ssl, const char* message);
void receive_message(SSL *ssl);

#endif //CHAT_IO_H