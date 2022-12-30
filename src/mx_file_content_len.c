#include "../inc/libmx.h"

int mx_file_content_len(int fd) {
    char buf;
    int lenght = 0;

    while (read(fd, &buf, 1) != 0) lenght ++;

    close(fd);
    return lenght;
}
