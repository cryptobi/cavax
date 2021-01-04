#ifndef _Z_CAVAX_NETWORK_MSG
#define _Z_CAVAX_NETWORK_MSG

/*
    https://crypto.bi/cavax/    
*/

#include "../rawbuf.h"
#include "opcodes.h"
#include "fields.h"

// current maximum fields in a network message
#define CAVAX_MAX_NETWORK_FIELDS 5

struct cavax_network_msg {
	enum CAVAX_NETWORK_OPCODES op;
	cavax_rawbuf raw_bufer;
    cavax_rawbuf *field_data[CAVAX_MAX_NETWORK_FIELDS];
	enum CAVAX_NETWORK_FIELDS fields[CAVAX_MAX_NETWORK_FIELDS];	
    unsigned char field_count;
};

struct cavax_network_msg cavax_network_messages[CAVAX_NETWORK_OPCODES_COUNT];
struct cavax_network_msg *cavax_network_parse_message(cavax_rawbuf *rawbuf);

#endif