/*
    https://crypto.bi/cavax/    
*/

#include <stdio.h>
#include <stdlib.h>

#include "cavax/network/network.h"

/* 
    The default network object.    
    This private structure lives throughout the cavax process lifetime.
*/
static struct cavax_network _cavax_default_network;

void cavax_network_listen() {
    // TODO Listen for inbound connections.    
}

void cavax_start_network() {
    printf("Starting CAVAX Network...");
    if (_cavax_default_network.connections == NULL) {
        _cavax_default_network.connections = calloc(1, CAVAX_INITIAL_CONNECTION_POOL_SIZE * sizeof(struct cavax_peer_connection));
    }    
    
    printf("DONE");
}

