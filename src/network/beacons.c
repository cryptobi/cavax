/*
    https://crypto.bi/cavax/    
*/

#include <unistd.h> // remove

#include "cavax/network/beacons.h"
#include "cavax/network/beacon-funcs.h"

void cavax_connect_beacons(struct cavax_host cavax_beacons[], size_t beacon_count, SSL_CTX *ctx) {

    for (size_t i = 0; i < beacon_count; i++) {

        cavax_beacon_connections[i].responded_version = false; // assume beacon is down

        printf("Connecting to %s : %d ...\n", cavax_beacons[i].ip, cavax_beacons[i].port);
        uint8_t buf[1024];
        int ret = 0;
        int conn = cavax_connect(cavax_beacons[i].ip, cavax_beacons[i].port);
        printf("Connected fd # %d. Upgrading ... \n", conn);
        SSL *avax_conn = cavax_upgrade_connection(conn, ctx);
        printf("DONE Upgrading connection with %s encryption.\n", SSL_get_cipher(avax_conn));

        uint8_t msgi[] = {
            0x00, 0x00, 0x00, 0x34, 0x01, 0x00, 0x00, 0x00, 0x01, 0x55, 0x86, 0x36, 0xc5, 0x00, 0x00, 0x00,
            0x00, 0x5f, 0x82, 0x4e, 0xea, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
            0xff, 0xc0, 0xa8, 0x01, 0xf1, 0x25, 0xb3, 0x00, 0x0f, 0x61, 0x76, 0x61, 0x6c, 0x61, 0x6e, 0x63,
            0x68, 0x65, 0x2f, 0x31, 0x2e, 0x30, 0x2e, 0x30
        };


        ret = SSL_write(avax_conn, msgi, sizeof(msgi));

        printf("Sent %d bytes.\n", ret);

        while ( ( ret = SSL_read(avax_conn, buf, 1024)) > 0 ) {            
                printf("SSL_read : fd %d recv'ed %d bytes\n", conn, ret);
                for (int x=0;x < ret;x++) {
                    printf("%02x ", buf[x]);
                }        
            printf("READ %d\n", ret);

            if (!(cavax_beacon_connections[i].responded_version) && (ret > 0) ) {
                cavax_beacon_connections[i].responded_version = true;
            }
                
        }
        
        printf("Conn %d connection established\n", conn);
                
        cavax_beacon_connections[i].fd = conn;
        cavax_beacon_connections[i].ssl = avax_conn;
    }
}

void cavax_disconnect_beacons(struct cavax_peer_connection cavax_beacons[], size_t beacon_count){
    for (size_t i=0;i<beacon_count;i++) {
        cavax_close_peer_connection(cavax_beacons + i);
    }
}

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
        cavax_beacons[i].id = cavax_beacon_ids[i]; // ID is read-only

        printf("IP %s PORT %d ID %s\n", cavax_beacons[i].ip, cavax_beacons[i].port, cavax_beacons[i].id);

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