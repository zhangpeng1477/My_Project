SUBDIRS	:= subdir1 subdir2 subdir3
.PHONY: $(SUBDIRS)

APPS	:= app
AOBJS	:= $(patsubst %.s, %.o, $(wildcard *.s))
COBJS	:= $(patsubst %.c, %.o, $(wildcard *.c))
CPPOBJS	:= $(patsubst %.cpp, %.o, $(wildcard *.cpp))
OBJS	:= $(AOBJS) $(COBJS) $(CPPOBJS)

CROSS	:= 
CC	:= $(CROSS)gcc
AR	:= $(CROSS)ar
INCLUDE	:= $(PWD)/include
CFLAGS	:= -Wall -O2 -g -I$(INCLUDE)
LDFLAGS	:= -lpthread -L$(PWD)/lib -l subdir1 -lsubdir2 -lsubdir3
TOPDIR	:= $(PWD)

export CFLAGS TOPDIR CC

all: $(OBJS)
	@for dir in $(SUBDIRS) ; \
		do $(MAKE) -C $$dir all CC=$(CC) AR=$(AR); \
	done

	$(CC) -o $(APPS) $(LDFLAGS) $(OBJS)

clean:
	rm -f $(APPS) $(OBJS)
	@for dir in $(SUBDIRS) ; \
		do $(MAKE) -C $$dir clean ; \
	done
