#include "kvs.h"

char* get(kvs_t* kvs, const char* key)
{
	/* do program here */
	node_t* current = kvs->db;

	while(current!=NULL) {
		if (current->key == key)
			break;
	}
	
	char* value = (char*)malloc(sizeof(char)*100);

	if(!value){
		printf("Failed to malloc\n");
		return NULL;
	}

	strcpy(value, current->value);
	return value;
}
