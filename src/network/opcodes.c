/*
    https://crypto.bi/cavax/    
*/


#include "cavax/network/opcodes.h"

// REF: network/commands.go
char *cavax_network_opcode_name(enum CAVAX_NETWORK_OPCODES op){
	switch (op) {
        case CAVAX_OP_GETVERSION:
            return "get_version";
        case CAVAX_OP_VERSION:
            return "version";
        case CAVAX_OP_GETPEERLIST:
            return "get_peerlist";
        case CAVAX_OP_PEERLIST:
            return "peerlist";
        case CAVAX_OP_PING:
            return "ping";
        case CAVAX_OP_PONG:
            return "pong";
        case CAVAX_OP_GETACCEPTEDFRONTIER:
            return "get_accepted_frontier";
        case CAVAX_OP_ACCEPTEDFRONTIER:
            return "accepted_frontier";
        case CAVAX_OP_GETACCEPTED:
            return "get_accepted";
        case CAVAX_OP_ACCEPTED:
            return "accepted";
        case CAVAX_OP_GET:
            return "get";
        case CAVAX_OP_GETANCESTORS:
            return "get_ancestors";
        case CAVAX_OP_PUT:
            return "put";
        case CAVAX_OP_MULTIPUT:
            return "multi_put";
        case CAVAX_OP_PUSHQUERY:
            return "push_query";
        case CAVAX_OP_PULLQUERY:
            return "pull_query";
        case CAVAX_OP_CHITS:
            return "chits";
        default:
            return "Unknown Op";
	}
}
