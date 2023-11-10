all:

static: static_lib
	gcc -c main2.c
	gcc -static -o prog2 main2.o ./libvector.a

static_lib: addvec.c multvec.c
	gcc -c addvec.c multvec.c
	ar rcs libvector.a addvec.o multvec.o

dynamic: dynamic_lib
	gcc -o dll dll.c -ldl

dynamic_lib:
	gcc -shared -o libvector.so addvec.c multvec.c

clean:
	rm *.o prog2

# SRCS = static_main.c
# LIBSRCS = open.c close.c set.c get.c 
# TARG = kvs_static

# CC = gcc
# OPTS = -Wall -g
# LIBS = -L. -lkvs

# OBJS = $(SRCS:.c=.o)
# LOBJS = $(LIBSRCS:.c=.o)
# LARS = libkvs.a


# all: 

# static: $(TARG)

# $(TARG) : $(OBJS) $(LARS)
# 	$(CC) -o $(TARG) $(OBJS) $(LIBS) 

# $(LARS) : $(LOBJS)
# 	ar rs $(LARS) $(LOBJS)

# %.o: %.c
# 	$(CC) $(OPTS) -c $< -o $@

# clean:
# 	rm -f $(OBJS) $(LOBJS) $(LARS) $(TARG)