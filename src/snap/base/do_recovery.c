//do_recovery.c
#include "kvs.h"

int do_recovery(kvs_t* kvs){
    FILE* snapshot_fp = fopen("kvs.img", "r");
    
    if (!snapshot_fp) {
        printf("리커버리 파일 없음\n");
        return -1;
    }
    
    char key[100];
    char value[10000];
    
	while(!feof(snapshot_fp)) {
		fscanf(snapshot_fp, "%[^,],%s\n", key, value);
        set(kvs, key, value);
	}

    printf("recovery complete, items = %d \n",kvs->items);
    fclose(snapshot_fp);

    return 0;
}