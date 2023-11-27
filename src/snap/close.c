//close.c
#include "kvs.h"

int close(kvs_t* kvs) {
    kvs->items = 0;
    for (int i=0; i<hash_size; i++) {
        free(kvs->db[i]->value);
        free(kvs->db[i]);
    }
    free(kvs);
    return 0;
}