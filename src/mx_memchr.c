#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *copy = (unsigned char *) s;

    for (size_t i = 0; i < n; i++)
        if (copy[i] == (char) c) return (void *) &copy[i];

    return NULL;
}
