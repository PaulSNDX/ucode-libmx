#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    if (n < 1) return 0;

    const unsigned char *copy1 = s1;
    const unsigned char *copy2 = s2;
    size_t i = 0;

    for (; i < n && copy1[i] == copy2[i]; i++)
        if (copy1[i] == '\0' && copy2[i]== '\0') return 0;

    return copy1[i] - copy2[i];
}
