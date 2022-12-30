#include "../inc/libmx.h"

char *mx_file_to_str(const char *filename) {
    int fd = open(filename, O_RDONLY);

    if (fd > 0) {
        int lenght = mx_file_content_len(fd);

        if (!lenght) return NULL;
        
        int fd1 = open(filename, O_RDONLY);        
        char *str = mx_strnew(lenght);
        read(fd1, str, lenght);
        close(fd1);
        return str;
    }
    return NULL;
}
