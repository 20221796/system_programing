//close.c
#include "kvs.h"

int close(kvs_t* kvs)
{
	/* do program */

    node_t* current = kvs->db;
    while (current != NULL) {
        node_t* next = current->next;
        free(current);
        current = next;
    }
	
	return 0;
}
