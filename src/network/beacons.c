/*
    https://crypto.bi/cavax/    
*/

#include <unistd.h> // remove

#include "cavax/network/beacons.h"
#include "cavax/network/beacon-funcs.h"
#include "cavax/network/msg.h"
#include "cavax/network/peer.h"

void cavax_connect_beacons(struct cavax_host cavax_beacons[], size_t beacon_count, SSL_CTX *ctx) {

    for (size_t i = 0; i < beacon_count; i++) {

        cavax_beacon_connections[i].responded_version = false; // assume beacon is down
        cavax_beacon_connections[i].beacon_index = i;
        cavax_beacon_connections[i].is_beacon = true;

        printf("Connecting to %s : %d ...\n", cavax_beacons[i].ip, cavax_beacons[i].port);
        
        int conn = cavax_connect(cavax_beacons[i].ip, cavax_beacons[i].port);
        printf("Connected fd # %d. Upgrading ... \n", conn);
        SSL *avax_conn = cavax_upgrade_connection(conn, ctx);
        printf("DONE Upgrading connection with %s encryption.\n", SSL_get_cipher(avax_conn));        
                
        cavax_beacon_connections[i].fd = conn;        
        cavax_beacon_connections[i].ssl = avax_conn;

        cavax_peer_thread(cavax_beacon_connections + i);
    }
}

void cavax_disconnect_beacons(struct cavax_peer_connection cavax_beacons[], size_t beacon_count){
    for (size_t i=0;i<beacon_count;i++) {
        cavax_close_peer_connection(cavax_beacons + i);
    }
}

/*
    Load and connect beacons.
    Beacons are regular hosts, except they should be assumed more trustworthy.
*/
void cavax_init_beacons() {

    SSL_CTX *ctx;
    const SSL_METHOD *method = TLS_client_method();

    for (size_t i=0;i<CAVAX_BEACON_LIST_SIZE;i++) {

        size_t j = 0;

        // find the colon :
        char *port_ptr = 0;
        for (;j<strlen(cavax_beacon_ips[i]);j++) {
            if (cavax_beacon_ips[i][j] == ':') {
                port_ptr = &cavax_beacon_ips[i][j] + 1;
                break;
            }
        }

        memcpy(cavax_beacons[i].ip, cavax_beacon_ips[i], (port_ptr - *(cavax_beacon_ips + i) - 1));
        cavax_beacons[i].port = (uint16_t) atoi(port_ptr);
        // TODO get id from string 
        // cavax_beacons[i].id = cavax_beacon_ids[i]; // ID is read-only

        //printf("IP %s PORT %d ID %s\n", cavax_beacons[i].ip, cavax_beacons[i].port, cavax_beacons[i].id);
        

    }


    printf("Loading %lu Beacons...\n", CAVAX_BEACON_LIST_SIZE);       

    printf("Init SSL ... ");
    SSL_library_init();
    printf("DONE\n");

    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    ctx = SSL_CTX_new(method);

    if ( ctx == NULL )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    
    cavax_connect_beacons(cavax_beacons, CAVAX_BEACON_LIST_SIZE, ctx);    
}


void cavax_stop_beacons() {
    cavax_disconnect_beacons(cavax_beacon_connections, CAVAX_BEACON_LIST_SIZE);
}

struct cavax_host *cavax_get_random_beacon(void) {
    return NULL;
}