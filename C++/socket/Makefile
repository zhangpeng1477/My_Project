CROSS	:= 
CC	:= $(CROSS)g++
AR	:= $(CROSS)ar
INCLUDE	:= $(PWD)/include
CXXFLAGS= -Wall -O2 -g -I $(PWD)/inlcude
LDFLAGS	:= -L$(PWD)/lib -lsocket
TOPDIR	:= $(PWD)

export CXXFLAGS TOPDIR CC AR

all : libsocket.a server client

libsocket.a : lib
	$(MAKE) -C lib all CC=$(CC) AR=$(AR)

server: server.o
	$(CC) -o $@ $^ $(LDFLAGS)

client: client.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o : %.cc
	$(CC) $(CXXFLAGS) -c $^

.PHONY: clean

clean:
	make -C lib clean
	rm -rf *.o server client