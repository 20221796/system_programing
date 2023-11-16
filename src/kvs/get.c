//get.c
#include "kvs.h"

char* get(kvs_t* kvs, const char* key)
{
	node_t* current = kvs->db;

	while(1) {
		if (current==NULL) 
			return "-1";
		else if (strcmp(current->key, key) == 0)
			break;
		current = current->next;
	}

	char* value = (char*)malloc(sizeof(char)*20);

	if(!value){
		printf("Failed to malloc\n");
		return NULL;
	}
	
	strcpy(value, current->value);
	return value;
}