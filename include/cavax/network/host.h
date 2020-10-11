#ifndef _Z_CAVAX_NETWORK_HOST
#define _Z_CAVAX_NETWORK_HOST

/*
    https://crypto.bi/cavax/    
*/


struct cavax_host {
    char ip[22];
    uint16_t port;
    char *id;
};


#endif