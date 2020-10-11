#ifndef _Z_CAVAX_NETWORK_BEACON_FUNCS
#define _Z_CAVAX_NETWORK_BEACON_FUNCS

/*
    https://crypto.bi/cavax/    
*/

#include <string.h>
#include <stdint.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#include "connection.h"
#include "host.h"

void cavax_connect_beacons(struct cavax_host cavax_beacons[], size_t beacon_count, SSL_CTX *ctx);
void cavax_disconnect_beacons(struct cavax_peer_connection cavax_beacons[], size_t beacon_count);

struct cavax_host *cavax_get_random_beacon(void);

/*
    Initialize and connect beacons.
*/
void cavax_init_beacons();
void cavax_stop_beacons();

#endif