#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (big_len <= 0 || little_len <= 0) return NULL;

    char *copy_str = (char *) big;
    char *copy_substr = (char *) little;

    while (big_len-- - little_len >= 0)
        if (mx_memcmp(copy_str++, copy_substr, little_len - 1) == 0)
            return --copy_str;

    return NULL;
}
