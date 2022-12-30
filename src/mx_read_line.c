#include "../inc/libmx.h"

static void mx_del_new(char **lineptr) {
    mx_strdel(lineptr);
    *lineptr = mx_strnew(1);
}

static int mx_write_buf(char **lineptr, char buf, int bytes) {
    (*lineptr) = mx_realloc(*lineptr, ++bytes);
    (*lineptr)[bytes - 1] = buf;
    return bytes;
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (lineptr != NULL) mx_strdel(lineptr);
    
    *lineptr = mx_strnew(1);

    if (fd < 1 || !buf_size) return -2;

    int bytes = 0;
    char buf;

    if (read(fd, &buf, 1)) {
        if (buf == delim) return bytes;

        bytes = mx_write_buf(lineptr, buf, bytes);
    } else return -1;

    while (read(fd, &buf, 1) && buf != delim)
        bytes = mx_write_buf(lineptr, buf, bytes);

    if (buf != delim) {
        mx_del_new(lineptr);
        return 0;
    }

    (*lineptr) = mx_realloc(*lineptr, bytes + 1);
    mx_memset(&(*lineptr)[bytes], '\0', malloc_size(*lineptr) - bytes);
    return bytes;
}
