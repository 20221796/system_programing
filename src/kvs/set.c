//set.c
#include "kvs.h"

int set(kvs_t* kvs, const char* key, const char* value) {
    node_t* current = kvs->db;
	
    if (current == NULL) {
        node_t* data = (node_t*)malloc(sizeof(node_t));
		data->value = (char*)malloc((strlen(value) + 1) * sizeof(char));
		
        if (!data) {
            printf("메모리 할당 실패\n");
            return -1;
        }

        data->next = NULL;
        strcpy(data->key, key);
        strcpy(data->value, value);

        kvs->db = data;
        kvs->items++;
        return 0;
    }

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            strcpy(current->value, value);
            return 0;
        }

        if (current->next == NULL) {
            node_t* data = (node_t*)malloc(sizeof(node_t));
			data->value = (char*)malloc((strlen(value) + 1) * sizeof(char));

            if (!data)
			{
                printf("메모리 할당 실패\n");
                return -1;
            }

            data->next = NULL;
            strcpy(data->key, key);
            strcpy(data->value, value);

            current->next = data;
            kvs->items++;
            return 0;
        }
        current = current->next;
    }

    return -1;
}