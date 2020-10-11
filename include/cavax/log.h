#ifndef _Z_CAVAX_LOG
#define _Z_CAVAX_LOG

/*
    https://crypto.bi/cavax/    
*/

enum cavax_log_message_type_e {
    CAVAX_MESSAGE_INFO,
    CAVAX_MESSAGE_ERROR,
    CAVAX_MESSAGE_WARNING,
    CAVAX_MESSAGE_DEBUG,
};

void cavax_log(const char *msg, enum cavax_log_message_type_e typ);



#endif