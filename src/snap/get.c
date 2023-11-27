//get.c
#include "kvs.h"
#include "hash.h"

char* get(kvs_t* kvs, const char* key)
{
	int index = hash(key);
	if (kvs->db[index] == NULL)
		return "-1";

	char* value = (char*)malloc((strlen(kvs->db[index]->value) + 1) * sizeof(char));

	if(!value){
		printf("Failed to malloc\n");
		return NULL;
	}

	strcpy(value, kvs->db[index]->value); //value에 값을 복사해서 return
	return value;
}