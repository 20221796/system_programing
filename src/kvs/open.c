//open.c
#include "kvs.h"

kvs_t* open()
{
	kvs_t* kvs = (kvs_t*) malloc (sizeof(kvs_t));

	if(kvs)
		kvs->items = 0;
	printf("%d\n", kvs->items);

	return kvs;
}