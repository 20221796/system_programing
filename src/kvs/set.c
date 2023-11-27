//set.c
#include "kvs.h"

//기존 방식에서는 current의 뒤에 data를 넣어서 db의 길이가 길어질 때마다 실행 시간이 증가
//같은 key값이 나왔을 때 update도 따로 해줘야해서 시간이 더더욱 오래걸렸음 
//data를 뒤가 아니라 앞에 넣어서 공간을 더 쓰는 대신 속도 증가

int set(kvs_t* kvs, const char* key, const char* value) {
    node_t* current = kvs->db;
    node_t* data = (node_t*)malloc(sizeof(node_t));
    data->value = (char*)malloc((strlen(value) + 1) * sizeof(char));

    if (!data || !(data->value)) {
        printf("메모리 할당 실패\n");
        return -1;
    }

    strcpy(data->key, key);
    strcpy(data->value, value);

    kvs->db = data;
    data->next = current;
    kvs->items++;
}

// int set(kvs_t* kvs, const char* key, const char* value) {
//     node_t* current = kvs->db;
	
//     if (current == NULL) {
//         node_t* data = (node_t*)malloc(sizeof(node_t));
// 		data->value = (char*)malloc((strlen(value) + 1) * sizeof(char));
		
//         if (!data) {
//             printf("메모리 할당 실패\n");
//             return -1;
//         }

        
//         data->next = NULL;
//         strcpy(data->key, key);
//         strcpy(data->value, value);

//         kvs->db = data;
//         kvs->items++;
//         return 0;
//     }

//     while (current != NULL) {
//         if (strcmp(current->key, key) == 0) {
//             strcpy(current->value, value);
//             return 0;
//         }

//         if (current->next == NULL) {
//             node_t* data = (node_t*)malloc(sizeof(node_t));
// 			data->value = (char*)malloc((strlen(value) + 1) * sizeof(char));

//             if (!data)
// 			{
//                 printf("메모리 할당 실패\n");
//                 return -1;
//             }

//             data->next = NULL;
//             strcpy(data->key, key);
//             strcpy(data->value, value);

//             current->next = data;
//             kvs->items++;
//             return 0;
//         }
//         current = current->next;
//     }

//     return -1;
// }