#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 256

int main(int argc, char* argv[]) {
    int ifd, ofd;
    char* buff;
    ssize_t nreads, nwrites;

    if (argc < 2) {
        fprintf(stdout, "No arguments\n");
        return 0;
    } 
    
    else if (argc == 2) {
        // output to stdout file
        ifd = open(argv[1], O_RDONLY);
        if (ifd < 0) {
            perror("open");
            return errno;
        }

        buff = (char*)malloc(sizeof(char) * BUFF_SIZE);
        if (!buff) {
            fprintf(stdout, "Failed to allocate memory\n");
            return -1;
        }

        while ((nreads = read(ifd, buff, BUFF_SIZE)) > 0) {
            if (write(STDOUT_FILENO, buff, nreads) < 0) {
                perror("write");
                return errno;
            }
        }
        free(buff);
        close(ifd);
    }

    else if (argc == 4 && !strcmp(argv[2], "into")) {
        // output to redirection file
        ifd = open(argv[1], O_RDONLY);
        if (ifd < 0) {
            perror("open");
            return errno;
        }

        buff = (char*)malloc(sizeof(char) * BUFF_SIZE);
        if (!buff) {
            fprintf(stdout, "Failed to allocate memory\n");
            return -1;
        }

        ofd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (ofd < 0) {
            perror("open");
            return errno;
        }

        while ((nreads = read(ifd, buff, BUFF_SIZE)) > 0)
        {
            if ((nwrites = write(ofd, buff, nreads)) < 0) {
                perror("write");
                return errno;
            }
        }
        free(buff);
        close(ifd);
        close(ofd);
    }

    else {
        fprintf(stdout, "Wrong arguments\n");
        return 0;
    }
    return 0;
}
