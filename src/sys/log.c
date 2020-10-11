/*
    https://crypto.bi/cavax/    
*/

#include "cavax/log.h"
#include <stdio.h>
#include <time.h>

void cavax_log(const char *msg, enum cavax_log_message_type_e typ) {

    time_t t;
    struct tm *info;

    time(&t);
    info = localtime(&t);
    char *sinfo = asctime(info);

    switch (typ) {
        case CAVAX_MESSAGE_INFO:
            printf("%s INFO: %s", sinfo, msg);
            break;
        case CAVAX_MESSAGE_ERROR:
            fprintf(stderr, "%s DEBUG %s", sinfo, msg);          
            break;
        case CAVAX_MESSAGE_WARNING:
            fprintf(stderr, "%s DEBUG %s", sinfo, msg);          
            break;
        case CAVAX_MESSAGE_DEBUG:            
            fprintf(stderr, "%s DEBUG %s", sinfo, msg);          
            break;
        default:
            fprintf(stderr, "%s LOG %s", sinfo, msg);          
    }
}