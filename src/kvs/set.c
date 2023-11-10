#include "kvs.h"

int set(kvs_t* kvs, const char* key, const char* value)
{
	node_t* current = kvs->db;
	node_t* data;
	current->next = data;
	data->next = NULL;
	kvs->items = kvs->items + 1;
	
	printf("set: %s, %s\n", key, value);
	/* do program here */
	strcpy(data->key, key);
	strcpy(data->value, value);

	return 0;
}
