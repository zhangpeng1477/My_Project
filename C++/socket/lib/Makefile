LIBS	:= $(TOPDIR)/lib/libsocket.a

CPPOBJS	:= $(patsubst %.cc, %.o, $(wildcard *.cc))
OBJS	:= $(CPPOBJS)

all: $(OBJS)
	ar cr $(LIBS) $^

clean:
	rm -f $(OBJS) $(LIBS)

