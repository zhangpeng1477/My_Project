CC	= gcc
CFLAGS	= -Wall -O2 -g -std=gnu99
LDFLAGS	= -lpthread
OBJS	= main.o mythr.o
APP	= app

$(APP) : $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) 

%.o: %.c
	$(CC) -c $(CFLAGS) $^

install:
	cp -a $(APP) /home/nfsdir
	
clean:
	rm -f $(OBJS) $(APP)
