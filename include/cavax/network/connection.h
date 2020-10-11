#ifndef _Z_CAVAX_NETWORK_CONNECTION
#define _Z_CAVAX_NETWORK_CONNECTION

/*
    https://crypto.bi/cavax/    
*/


#include <stdio.h>
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <stdbool.h>

struct cavax_peer_connection {
    int fd;
    SSL *ssl;
    bool responded_version; // mark true if host was live upon connection
};


int cavax_connect(const char *host, uint16_t port);
SSL *cavax_upgrade_connection(int fd, SSL_CTX *ssl_ctx);
void cavax_close_peer_connection(struct cavax_peer_connection *conn);
int cavax_connect(const char *host, uint16_t port);

#endif