#ifndef _Z_CAVAX_IDS
#define _Z_CAVAX_IDS

/*
    https://crypto.bi/cavax/    
*/

// long id, from 256 bit hashes
typedef unsigned char cavax_id_t[32];

// short id, from 160 bit hashes
typedef unsigned char cavax_short_id_t[20];

// id from short ids, e.g. NodeID-A6onFGyJjA37EZ7kYHANMR1PFRT8NmXrF
cavax_short_id_t *cavax_short_id_from_string(const char *str);

// id from long id string
cavax_short_id_t *cavax_id_from_string(const char *str);


#endif