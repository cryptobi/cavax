/*
    https://crypto.bi/cavax/    
*/

#include "cavax/rawbuf.h"
#include <string.h>
#include <stdlib.h>

cavax_rawbuf *cavax_rawbuf_new(long unsigned int size) {
    cavax_rawbuf *buf = calloc(1, sizeof(cavax_rawbuf));
    buf->buf = calloc(1, size);
    buf->buffer_size = size;
    buf->used_size = 0;
    return buf;
}

void cavax_rawbuf_free(cavax_rawbuf *buf) {
    free(buf->buf);
    free(buf);
}

int cavax_rawbuf_copy(cavax_rawbuf *dest, cavax_rawbuf *src) {

    unsigned char *bk = dest->buf;
    
    dest->buf = realloc(dest->buf, src->buffer_size);
    
    if (dest->buf == NULL) {
        dest->buf = bk;
        return -1;
    }

    memcpy(dest->buf, src->buf, src->buffer_size);
    dest->buffer_size = src->buffer_size;
    dest->used_size = src->used_size;

    return 0;
}
