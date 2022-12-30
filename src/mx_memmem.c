#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (big == NULL
        || little == NULL
        || big_len <= 0
        || little_len <= 0
        || big_len < little_len) return NULL;

    unsigned char *copy_str = (unsigned char *) big;
    unsigned char *copy_substr = (unsigned char *) little;

    while (big_len-- > 0 && *copy_str != '\0') {
        if (*copy_str == *copy_substr) {
            size_t temp = 0;
            while (little_len > temp) {
                if (copy_str[temp] != copy_substr[temp]) {
                    temp = 0;
                    break;
                }
                temp++;
            }
            if (temp) return copy_str;
        }
        copy_str++;
    }
    return NULL;
}
