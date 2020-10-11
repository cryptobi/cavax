#ifndef _Z_CAVAX_NETWORK_VLA
#define _Z_CAVAX_NETWORK_VLA

/*
    https://crypto.bi/cavax/    
*/


#include <stdint.h>
#include <stdlib.h>

struct cavax_variable_length_array {
    uint8_t *buf;
    size_t len;
};


#endif