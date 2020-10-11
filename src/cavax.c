/*
    https://crypto.bi/cavax/    
*/

#include <stdio.h>

#include "cavax/cavax.h"
#include "cavax/network/network.h"
#include "cavax/network/connection.h"
#include "cavax/network/beacon-funcs.h"


int main(int argc, char **argv) {

    printf("%s (%d) : DefaultMaxMessageSize %lu defaultSendQueueSize %lu defaultMaxNetworkPendingSendBytes %lu\n", 
    argv[0], argc,
    (long unsigned int)(DefaultMaxMessageSize / 1024), 
    (long unsigned int)(defaultSendQueueSize / 1024), 
    (long unsigned int)(defaultMaxNetworkPendingSendBytes / 1024));

    cavax_init_beacons();

    cavax_start_network();
    cavax_network_listen();

    cavax_stop_beacons();
    return EXIT_SUCCESS;
}