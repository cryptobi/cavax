/*
    https://crypto.bi/cavax/    
*/

#include "cavax/network/connect.h"
#include "cavax/network/ssl.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <openssl/err.h>

SSL *cavax_upgrade_connection(int fd, SSL_CTX *ssl_ctx) {

    SSL *ctx;
    int ret;

    ctx = SSL_new(ssl_ctx);
    
    if ( (ret = SSL_CTX_use_certificate_file(ssl_ctx, CavaxStakingCertFile, SSL_FILETYPE_PEM)) != 1) {
        fprintf(stderr, "ERROR: SSL_CTX_use_certificate_file %s NOT LOADED. Not PEM format?\n", CavaxStakingCertFile);
        fprintf(stderr, "Tip: Run avalanchego once to create cert file.\n");
    }
    
    if ( (ret = SSL_use_RSAPrivateKey_file(ctx, CavaxStakingKeyFile, SSL_FILETYPE_PEM)) != 1) {
        fprintf(stderr, "ERROR: SSL_use_RSAPrivateKey_file %s NOT LOADED. Not PEM format?\n", CavaxStakingKeyFile);
        fprintf(stderr, "Tip: Run avalanchego once to create key file.\n");
    }        
        
    ret = SSL_set_fd(ctx, fd); 

    if ( ret != 1 ){
        printf("Error SSL_set_fd %d\n", fd);
        ERR_print_errors_fp(stderr);
        SSL_free(ctx);
        return NULL;
    } else {
        printf("SSL_set_fd FD %d OK\n", fd);
    }

    ret = SSL_connect(ctx);

    if ( ret != 1 ){
        printf("Error SSL_connect fd %d\n", fd);
        ERR_print_errors_fp(stderr);
        SSL_free(ctx);
        return NULL;
    } else {
        printf("SSL_connect FD %d OK\n", fd);
    }
        
    return ctx;
}

void cavax_close_peer_connection(struct cavax_peer_connection *conn) {
    SSL_free(conn->ssl);
    close(conn->fd);
}


int cavax_connect(const char *host, uint16_t port) {

    int socket_desc;
    struct sockaddr_in server;


	socket_desc = socket(AF_INET , SOCK_STREAM , 0);

    if (socket_desc < 0) {
        fprintf(stderr, "CAN'T CREATE SOCKET\n");
        return -1;
    }
    
	server.sin_addr.s_addr = inet_addr(host);
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	
	if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0) {
		fprintf(stderr, "CAN'T CONNECT TO %s %d\n", host, port);
		return -1;
	}

    return socket_desc;

}