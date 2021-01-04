#ifndef _Z_CAVAX_NETWORK_CONNECTION
#define _Z_CAVAX_NETWORK_CONNECTION

/*
    https://crypto.bi/cavax/    
*/

#include <stdbool.h>
#include <openssl/ssl.h>
#include <pthread.h>

struct cavax_peer_connection {
    struct cavax_host *peer;
    int fd;
    // if this is a beacon connection, remember which
    bool is_beacon;
    int beacon_index; 
    SSL *ssl;
    // mark true if host was live on last connection attempt
    bool responded_version; 
    bool responded_peer_list; 
    char *version_string;
    size_t pending_bytes;
    bool connected;
    uint64_t last_sent;
    uint64_t last_received;
    pthread_t conn_thread;
};

int cavax_connect(const char *host, uint16_t port);
SSL *cavax_upgrade_connection(int fd, SSL_CTX *ssl_ctx);
void cavax_close_peer_connection(struct cavax_peer_connection *conn);
int cavax_connect(const char *host, uint16_t port);

#endif