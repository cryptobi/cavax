#ifndef _Z_CAVAX_RAWBUF
#define _Z_CAVAX_RAWBUF

/*
    https://crypto.bi/cavax/    
*/

typedef struct cavax_rawbuf {
	unsigned char *buf;
	long unsigned int buffer_size; // allocated size
	long unsigned int used_size; // used size
} cavax_rawbuf;

cavax_rawbuf *cavax_rawbuf_new(long unsigned int size);
int cavax_rawbuf_copy(cavax_rawbuf *dest, cavax_rawbuf *src);
void cavax_rawbuf_free(cavax_rawbuf *buf);

#endif
