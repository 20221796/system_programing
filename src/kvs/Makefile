all:

static: static_lib
	gcc -c static_main.c
	gcc -static -o kvs_static static_main.o -L. -lkvs

static_lib: open.c close.c set.c get.c
	gcc -c -fPIC open.c close.c set.c get.c
	ar rcs libkvs.a open.o close.o set.o get.o

dynamic: dynamic_lib
	gcc -o kvs_dynamic dynamic_main.c -ldl -L. -lkvs

dynamic_lib:
	export LD_LIBRARY_PATH := $(shell pwd):$(LD_LIBRARY_PATH)
	gcc -shared -o libkvs.so -fPIC open.c close.c set.c get.c

clean:
	rm -f *.o kvs_static kvs_dynamic *.a *.so answer.dat