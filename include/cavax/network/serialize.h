#ifndef _Z_CAVAX_NETWORK_SERIALIZE
#define _Z_CAVAX_NETWORK_SERIALIZE

/*
    https://crypto.bi/cavax/    
*/


#include <stdlib.h>
#include <stdint.h>

#include "ip.h"
#include "fla.h"
#include "vla.h"

// initial serialized buffer size in KB
// defaults to a typical page
#define CAVAX_SERIALIZED_BUF_SIZ (4 * 1024)

struct cavax_serialized_buff {
    void *buf;
    size_t len;
    void *pos; // current position in buf
};

typedef struct cavax_serialized_buff cavax_csb_t;


#define cavax_serialize_buf_len(csb) (csb->pos - csb->buf)
#define cavax_serialize_realloc_size(csb, siz) (cavax_serialize_buf_len(csb) + siz)
#define cavax_serialize_requires_realloc(csb, siz) ((cavax_serialize_buf_len(csb) + siz) > csb->len)

/*
    Create a new serialization buffer.
    If siz <= 0 then CAVAX_SERIALIZED_BUF_SIZ is used for the initial buffer size.
*/
cavax_csb_t *cavax_serialize_new(size_t siz);
void cavax_serialize_free(cavax_csb_t *csb);
void cavax_serialize_byte(cavax_csb_t *buf, unsigned char *c);
void cavax_serialize_short(cavax_csb_t *buf, uint16_t *s);
void cavax_serialize_int(cavax_csb_t *buf, uint32_t *i);
void cavax_serialize_long(cavax_csb_t *buf, uint64_t *l);
void cavax_serialize_ip(cavax_csb_t *buf, struct cavax_ip_address *ip);
void cavax_serialize_fla(cavax_csb_t *buf, struct cavax_fixed_length_array *fla);
void cavax_serialize_vla(cavax_csb_t *buf, struct cavax_variable_length_array *vla);
void cavax_serialize_string(cavax_csb_t *buf, char *s); // zero-terminated string

#endif