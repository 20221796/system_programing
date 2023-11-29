#include "kvs.h"
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 10100

int do_recovery(kvs_t* kvs){
    int snapshot_fd = open("kvs.img", O_RDONLY);
    
    if (snapshot_fd < 0) {
        printf("리커버리 파일 없음 \n");
        return -1;
    }
    
    char key[100];
    char value[10000];
    char buf[BUF_SIZE];
    int i, buf_index = 0, buf_len = 0;

    while ((buf_len = read(snapshot_fd, buf, BUF_SIZE)) > 0) {
        for(i = 0; i < buf_len; i++) {
            if(buf[i] == '\n') {
                buf[i] = '\0';
                sscanf(buf + buf_index, "%[^,],%s", key, value);
                set(kvs, key, value);
                buf_index = i + 1;
            }
        }
        // If no newline was found, move the file pointer back
        if(buf_index < buf_len) {
            lseek(snapshot_fd, buf_index - buf_len, SEEK_CUR);
        }
        buf_index = 0;
    }

    printf("recovery complete, items = %d \n",kvs->items);
    close(snapshot_fd);

    return 0;
}