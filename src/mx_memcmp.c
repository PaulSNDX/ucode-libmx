#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    if (n < 1) return 0;

    const unsigned char *copy1 = s1;
    const unsigned char *copy2 = s2;
    size_t i = 0;

    while (i <= n) {
        if (!copy1[i] || !copy2[i]) return 0;
        if (copy1[i] != copy2[i]) break;
        i++;
    }
    return copy1[i] - copy2[i];
}
