#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 1) return -2;

    char buf;
    unsigned long index = 0;
    char *temp = mx_strnew(buf_size);
    char *buffer = mx_strnew(buf_size);

    while (read(fd, &buf, 1) != 0 && buf_size > 0 && buf_size < 2147483648) {
        if (buf == delim || buf == '\0') {
            if (index == 0) *lineptr = "";
            else mx_strncpy(*lineptr, buffer, index);
            
            free(temp);
            free(buffer);
            return index;
        } else if (index >= buf_size) {
            buf_size++;

            free(temp);
            temp = mx_strnew(buf_size);
            mx_strncpy(temp, buffer, index);
            
            free(buffer);
            buffer = mx_strnew(buf_size);
            mx_strncpy(buffer, temp, index);
        }
        buffer[index++] = buf;
    }
    free(temp);
    free(buffer);
    return -1;
}
