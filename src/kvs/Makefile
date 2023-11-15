TARG_STATIC = kvs_static
TARG_DYNAMIC = kvs_dynamic

CC = gcc
OPTS = -Wall -g
LIBS = -L. -lkvs

STATIC_OBJS = static_main.o
DYNAMIC_OBJS = dynamic_main.o
LOBJS = open.o close.o set.o get.o
LARS_STATIC = libkvs.a
LARS_DYNAMIC = libkvs.so

all: static dynamic

static: $(TARG_STATIC)

dynamic: $(LARS_DYNAMIC) $(TARG_DYNAMIC)

$(TARG_STATIC): $(STATIC_OBJS) $(LARS_STATIC)
	$(CC) -static -o $(TARG_STATIC) $(STATIC_OBJS) $(LARS_STATIC) $(LIBS)

$(TARG_DYNAMIC): $(DYNAMIC_OBJS) $(LARS_DYNAMIC)
	$(CC) -o $(TARG_DYNAMIC) $(DYNAMIC_OBJS) -ldl $(LIBS) -Wl,-rpath,. $(LARS_DYNAMIC)

$(LARS_STATIC): $(LOBJS)
	ar rs $(LARS_STATIC) $(LOBJS)

$(LARS_DYNAMIC): $(LOBJS)
	$(CC) -o $(LARS_DYNAMIC) $(LOBJS) -shared -fPIC

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm -f $(STATIC_OBJS) $(DYNAMIC_OBJS) $(LOBJS) $(LARS_STATIC) $(LARS_DYNAMIC) $(TARG_STATIC) $(TARG_DYNAMIC)

# all:

# static: static_lib
# 	gcc -c static_main.c
# 	gcc -static -o kvs_static static_main.o ./libkvs.a

# static_lib: open.c close.c set.c get.c
# 	gcc -c open.c close.c set.c get.c
# 	ar rcs libkvs.a open.o close.o set.o get.o

# dynamic: dynamic_lib
# 	gcc -o kvs_dynamic dynamic_main.c -ldl

# dynamic_lib:
# 	gcc -shared -o libkvs.so open.c close.c set.c get.c 

# clean:
# 	rm *.o kvs_static kvs_dynamic *.a *.so