# https://crypto.bi/cavax/    

AUTOMAKE_OPTIONS=subdir-objects
AM_LDFLAGS=
AM_CPPFLAGS = -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
ACLOCAL_AMFLAGS=-I m4 

lib_LIBRARIES = lib/libcavax.a
lib_libcavax_a_SOURCES = src/network/network.c src/network/beacons.c src/network/msg.c src/network/connect.c src/sys/log.c src/utils/wrappers.c src/rawbuf.c src/network/peer.c
lib_libcavax_a_CPPFLAGS = -Wall -Wextra -pedantic-errors -I./include 
lib_libcavax_a_LIBADD=

# -lglib-2.0 -lpthread -lm -lssl -lcrypto

bin_PROGRAMS=bin/cavax
bin_cavax_SOURCES=src/cavax.c 
bin_cavax_CPPFLAGS = -Wall -Wextra -pedantic-errors -I./include 
bin_cavax_LDFLAGS = 
bin_cavax_LDADD=lib/libcavax.a -lglib-2.0 -lpthread -lm -lssl -lcrypto