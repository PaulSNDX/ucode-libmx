#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *copy = (unsigned char *)s;
    char symbol = (char) c;

    for (size_t i = 0; i < n; i++)
        if (copy[i] == symbol) return copy;

    return NULL;
}
