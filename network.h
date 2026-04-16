#ifndef NETWORK_H
#define NETWORK_H

#include <openssl/ssl.h>
#include <openssl/err.h>

SSL* connect_to_server(const char *ip_address, int port);

#endif NETWORK_H