#include "../inc/libmx.h"

static int file_content_lenght(int fd) {
    char buf;
    int lenght = 0;

    while (read(fd, &buf, 1) != 0) lenght ++;

    close(fd);
    return lenght;
}

char *mx_file_to_str(const char *filename) {
    int fd = open(filename, O_RDONLY);

    if (fd > 0) {
        int lenght = file_content_lenght(fd);

        if (!lenght) return NULL;
        
        int fd1 = open(filename, O_RDONLY);        
        char *str = mx_strnew(lenght);
        read(fd1, str, lenght);
        close(fd1);
        return str;
    }
    return NULL;
}
