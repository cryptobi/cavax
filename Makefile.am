# https://crypto.bi/cavax/    
AUTOMAKE_OPTIONS=subdir-objects
AM_LDFLAGS=
AM_CPPFLAGS = -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
ACLOCAL_AMFLAGS=-I m4 
bin_PROGRAMS=bin/cavax
bin_cavax_SOURCES=src/cavax.c src/network/network.c src/network/beacons.c src/network/connect.c src/sys/log.c
bin_cavax_CPPFLAGS = -Wall -Wextra -pedantic-errors -I./include 
bin_cavax_LDFLAGS = 
bin_cavax_LDADD=-lglib-2.0 -lpthread -lm -lssl -lcrypto