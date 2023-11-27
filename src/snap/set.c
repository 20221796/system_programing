//set.c
#include "kvs.h"
#include "hash.h"

int set(kvs_t* kvs, const char* key, const char* value) {
    int index = hash(key);
    node_t* data = (node_t*)malloc(sizeof(node_t));
    data->value = (char*)malloc((strlen(value) + 1) * sizeof(char));

    if (!data || !(data->value)) {
        printf("메모리 할당 실패\n");
        return -1;
    }

    strcpy(data->key, key);
    strcpy(data->value, value);

    kvs->db[index] = data;
    kvs->items++;
    
    return 0;
}