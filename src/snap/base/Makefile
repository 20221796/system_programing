SOURCES = open.c close.c set.c get.c hash.c do_snapshot.c do_recovery.c
OBJECTS = $(SOURCES:.c=.o)

all: static

static: static_lib
	gcc -c static_main.c
	gcc -static -o kvs_static static_main.o -L. -lkvs

static_lib: $(SOURCES)
	gcc -c -fPIC $(SOURCES)
	ar rcs libkvs.a $(OBJECTS)

clean:
	rm -f *.o kvs_static *.a *.so answer.dat kvs.img