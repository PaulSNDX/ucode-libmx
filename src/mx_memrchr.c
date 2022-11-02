#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *copy = (unsigned char *)s + mx_strlen(s);
    char symbol = (unsigned char) c;

    for (size_t i = 0; i < n; i++) {
        if (*copy == symbol) return copy;
        copy--;
    }

    return NULL;
}
