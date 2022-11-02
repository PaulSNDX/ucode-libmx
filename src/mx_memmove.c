#include "../inc/libmx.h"

//dst size have to be less or equal to src size
void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *temp = malloc(len);
    mx_memcpy(temp, src, len);
    mx_memcpy(dst, temp, len);
    free(temp);
    return dst;
}
