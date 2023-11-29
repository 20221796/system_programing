//do_snapshot.c
#include "kvs.h"
#include <fcntl.h>
#include <unistd.h>

int do_snapshot(kvs_t* kvs){
    int snapshot_fd = open("kvs.img", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    
    if (snapshot_fd < 0) {
        printf("파일 열기 실패");
        return -1;
    }

    char buf[10000];
    for (int i=0; i<hash_size; i++) {
        if (kvs->db[i]!=NULL) {
            sprintf(buf, "tweet%d,%s\n",i,kvs->db[i]->value);
            write(snapshot_fd, buf, strlen(buf));
        }
    }

    close(snapshot_fd);
    return 0;
}