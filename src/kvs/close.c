//close.c
#include "kvs.h"

int close(kvs_t* kvs) {
    node_t* current = kvs->db;
    
    while (current != NULL) { //노드를 끝까지 탐색하면 current에 할당된 메모리를 해제
        node_t* next = current->next;
        free(current->value); 
        free(current);          
        current = next;
    }
    kvs->db = NULL;
    kvs->items = 0;
    return 0;
}