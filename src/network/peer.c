/*
    https://crypto.bi/cavax/    
*/


#include "cavax/network/peer.h"
#include "cavax/network/msg.h"
#include "cavax/rawbuf.h"
#include <openssl/ssl.h>

static void *_cavax_peer_thread(void *vcpc) {
    struct cavax_peer_connection *cpc = vcpc;

    printf("thread started %d\n", cpc->fd);

    uint8_t msgi[] = {
        0x00, 0x00, 0x00, 0x34, 0x01, 0x00, 0x00, 0x00, 0x01, 0x55, 0x86, 0x36, 0xc5, 0x00, 0x00, 0x00,
        0x00, 0x5f, 0x82, 0x4e, 0xea, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
        0xff, 0xc0, 0xa8, 0x01, 0xf1, 0x25, 0xb3, 0x00, 0x0f, 0x61, 0x76, 0x61, 0x6c, 0x61, 0x6e, 0x63,
        0x68, 0x65, 0x2f, 0x31, 0x2e, 0x30, 0x2e, 0x30
    };

    uint8_t buf[1024];        
    int ret = SSL_write(cpc->ssl, msgi, sizeof(msgi));

    printf("Sent %d bytes.\n", ret);

    while ( ( ret = SSL_read(cpc->ssl, buf, 1024)) > 0 ) {            

        printf("SSL_read : fd %d recv'ed %d bytes\n", cpc->fd, ret);

        for (int x=0;x < ret;x++) {
            printf("%02x ", buf[x]);
        }        

        printf("READ %d\n", ret);

        if (ret > 0) {
            cavax_rawbuf bx = {
                buf, ret, ret
            };
            struct cavax_network_msg *msg = cavax_network_parse_message(&bx);
            printf("cavax_connect_beacons msg has %d fields\n", msg->field_count);
        }

        if (!(cpc->responded_version) && (ret > 0) ) {
            cpc->responded_version = true;
        }            
            
    }

    return vcpc;
}


int cavax_peer_thread(struct cavax_peer_connection *cpc) {

    int ret = pthread_create(&(cpc->conn_thread), NULL, _cavax_peer_thread, cpc);

    if (ret != 0) {
        return ret;
    }

    return -1;
}