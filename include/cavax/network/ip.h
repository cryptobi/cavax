#ifndef _Z_CAVAX_NETWORK_IP
#define _Z_CAVAX_NETWORK_IP

/*
    https://crypto.bi/cavax/    
*/


#include <stdint.h>

// The Avalanche IP serialization contains the port number.
struct cavax_ip_address {
    uint8_t buf[16];
    uint16_t port;
};


#endif