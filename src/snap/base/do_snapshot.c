//do_snapshot.c
#include "kvs.h"

int do_snapshot(kvs_t* kvs){
    FILE* snapshot_fp = fopen("kvs.img", "w");
    
    if (!snapshot_fp) {
        printf("파일 열기 실패\n");
        return -1;
    }

    for (int i=0; i<hash_size; i++) {
        if (kvs->db[i]!=NULL) {
            fprintf(snapshot_fp, "tweet%d,%s\n",i,kvs->db[i]->value);
        }
    }

    fclose(snapshot_fp);
    return 0;
}