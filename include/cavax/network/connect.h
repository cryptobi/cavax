#ifndef _Z_CAVAX_NETWORK_CONNECT
#define _Z_CAVAX_NETWORK_CONNECT

/*
    https://crypto.bi/cavax/    
*/


#include <openssl/ssl.h>


#include "connection.h"


/*
    Connect a socket to host : port and return socket fd.
*/
int cavax_connect(const char *host, uint16_t port);
SSL *cavax_upgrade_connection(int fd, SSL_CTX *ssl_ctx);
int cavax_connect(const char *host, uint16_t port);

#endif