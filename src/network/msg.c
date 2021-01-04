/*
    https://crypto.bi/cavax/    
*/

#include "cavax/network/msg.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct cavax_network_msg cavax_network_messages[] = {
    {
        CAVAX_OP_GETVERSION,
        {
            NULL, 0, 0
        },
        {0},
        {0},
        0
    },
    {
        CAVAX_OP_VERSION,
        {
            NULL, 0, 0
        },
        {0},
        {   
            CAVAX_FIELD_NETWORKID, 
            CAVAX_FIELD_NODEID, 
            CAVAX_FIELD_MYTIME, 
            CAVAX_FIELD_IP, 
            CAVAX_FIELD_VERSIONSTR
        },
        5
    },
    {
        CAVAX_OP_GETPEERLIST,
        {
            NULL, 0, 0
        },
        {0},
        {0},
        0
    },
    {
        CAVAX_OP_PEERLIST,
        {
            NULL, 0, 0
        },
        {0},
        {
            CAVAX_FIELD_PEERS
        },
        1
    },
    {
        CAVAX_OP_PING,
        {
            NULL, 0, 0
        },
        {0},
        {0},
        0
    },
    {
        CAVAX_OP_PONG,
        {
            NULL, 0, 0
        },
        {0},
        {0},
        0
    },
    {
        CAVAX_OP_GETACCEPTEDFRONTIER,
        {
            NULL, 0, 0
        },
        {0},
        {
            CAVAX_FIELD_CHAINID,
            CAVAX_FIELD_REQUESTID,
            CAVAX_FIELD_DEADLINE,
        },
        3
    },
    {
        CAVAX_OP_ACCEPTEDFRONTIER,
        {
            NULL, 0, 0
        },
        {0},
        {
            CAVAX_FIELD_CHAINID,
            CAVAX_FIELD_REQUESTID,
            CAVAX_FIELD_CONTAINERID,
        },
        3
    },
    {
        CAVAX_OP_GETACCEPTED,
        {
            NULL, 0, 0
        },
        {0},
        {
            CAVAX_FIELD_CHAINID,
            CAVAX_FIELD_REQUESTID,
            CAVAX_FIELD_DEADLINE,
            CAVAX_FIELD_CONTAINERIDS,
        },
        4
    },
    {
        CAVAX_OP_ACCEPTED,
        {
            NULL, 0, 0
        },
        {0},
        {
            CAVAX_FIELD_CHAINID,
            CAVAX_FIELD_REQUESTID,
            CAVAX_FIELD_CONTAINERIDS,            
        },
        3
    },
    {
        CAVAX_OP_GETANCESTORS,
        {
            NULL, 0, 0
        },
        {0},
        {
            CAVAX_FIELD_CHAINID,
            CAVAX_FIELD_REQUESTID,
            CAVAX_FIELD_DEADLINE,
            CAVAX_FIELD_CONTAINERID,            
        },
        4
    },
    {
        CAVAX_OP_MULTIPUT,
        {
            NULL, 0, 0
        },
        {0},
        {
            CAVAX_FIELD_CHAINID,
            CAVAX_FIELD_REQUESTID,
            CAVAX_FIELD_MULTICONTAINERBYTES,            
        },
        3
    },
    {
        CAVAX_OP_GET,
        {
            NULL, 0, 0
        },
        {0},
        {
            CAVAX_FIELD_CHAINID,
            CAVAX_FIELD_REQUESTID,
            CAVAX_FIELD_DEADLINE,
            CAVAX_FIELD_CONTAINERID,
        },
        4
    },
    {
        CAVAX_OP_PUT,
        {
            NULL, 0, 0
        },
        {0},
        {
            CAVAX_FIELD_CHAINID,
            CAVAX_FIELD_REQUESTID,
            CAVAX_FIELD_CONTAINERID,
            CAVAX_FIELD_CONTAINERBYTES,
        },
        4
    },
    {
        CAVAX_OP_PUSHQUERY,
        {
            NULL, 0, 0
        },
        {0},
        {
            CAVAX_FIELD_CHAINID,
            CAVAX_FIELD_REQUESTID,
            CAVAX_FIELD_DEADLINE,
            CAVAX_FIELD_CONTAINERID,
            CAVAX_FIELD_CONTAINERBYTES,
        },
        5
    },
    {
        CAVAX_OP_PULLQUERY,
        {
            NULL, 0, 0
        },
        {0},
        {
            CAVAX_FIELD_CHAINID,
            CAVAX_FIELD_REQUESTID,
            CAVAX_FIELD_DEADLINE,
            CAVAX_FIELD_CONTAINERID,            
        },
        4
    },
    {
        CAVAX_OP_CHITS,
        {
            NULL, 0, 0
        },
        {0},
        {
            CAVAX_FIELD_CHAINID,
            CAVAX_FIELD_REQUESTID,
            CAVAX_FIELD_CONTAINERIDS,            
        },
        3
    },
};


struct cavax_network_msg *cavax_network_parse_message(cavax_rawbuf *rawbuf) {

    struct cavax_network_msg *msg = calloc(1, sizeof(struct cavax_network_msg));
    cavax_rawbuf_copy(&(msg->raw_bufer), rawbuf);

    printf("cavax_network_parse_message BUFFER IS %lu BYTES\n", msg->raw_bufer.buffer_size);

    return msg;
}