#ifndef _Z_CAVAX_NETWORK_HOST
#define _Z_CAVAX_NETWORK_HOST

/*
    https://crypto.bi/cavax/    
*/

#include "cavax/ids.h"

struct cavax_host {
    char ip[22];
    uint16_t port;
    cavax_short_id_t *id;
};


#endif