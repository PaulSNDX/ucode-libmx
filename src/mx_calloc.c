#include "../inc/libmx.h"

void *mx_calloc(size_t count, size_t size) {
    size_t alloc_size = count * size;
    void *new = malloc(alloc_size);

    if (new) {
        mx_memset(new, 0, alloc_size);
        return new;
    } else return NULL;
}
