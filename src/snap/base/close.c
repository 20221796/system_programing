//close.c
#include "kvs.h"

int close_kvs(kvs_t* kvs) {
    kvs->items = 0;
    
    for (int i=0; i<hash_size; i++) {
        if (kvs->db[i]!=NULL) {
        free(kvs->db[i]->value);
        free(kvs->db[i]);
        }
    }
    free(kvs);
    return 0;
}