//get.c
#include "kvs.h"

char* get(kvs_t* kvs, const char* key)
{
	node_t* current = kvs->db;

	while(1) {
		if (current==NULL) //key를 찾지 못하고 맨 끝에 도달하면 -1을 리턴
			return "-1";
		else if (strcmp(current->key, key) == 0)
			break;
		current = current->next; //key값을 찾을 때 까지 db안을 탐색
	}

	char* value = (char*)malloc((strlen(current->value) + 1) * sizeof(char));

	if(!value){
		printf("Failed to malloc\n");
		return NULL;
	}
	
	strcpy(value, current->value); //value에 값을 복사해서 return
	return value;
}