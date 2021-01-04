/*
    https://crypto.bi/cavax/    
*/

#include "cavax/network/fields.h"


char *cavax_network_field_name(enum CAVAX_NETWORK_FIELDS f){
	switch (f) {
        case CAVAX_FIELD_VERSIONSTR:
            return "VersionStr";
        case CAVAX_FIELD_NETWORKID:
            return "NetworkID";
        case CAVAX_FIELD_NODEID:
            return "NodeID";
        case CAVAX_FIELD_MYTIME:
            return "MyTime";
        case CAVAX_FIELD_IP:
            return "IP";
        case CAVAX_FIELD_PEERS:
            return "Peers";
        case CAVAX_FIELD_CHAINID:
            return "ChainID";
        case CAVAX_FIELD_REQUESTID:
            return "RequestID";
        case CAVAX_FIELD_DEADLINE:
            return "Deadline";
        case CAVAX_FIELD_CONTAINERID:
            return "ContainerID";
        case CAVAX_FIELD_CONTAINERBYTES:
            return "Container Bytes";
        case CAVAX_FIELD_CONTAINERIDS:
            return "Container IDs";
        case CAVAX_FIELD_MULTICONTAINERBYTES:
            return "MultiContainerBytes";
        default:
            return "Unknown Field";
	}
}