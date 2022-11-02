#include "../inc/libmx.h"

//#include <malloc.h> // for Linux -> malloc_usable_size
//#include <malloc/malloc.h> // for IOS -> malloc_size

void *mx_realloc(void * ptr, size_t size) {
    void *new;

    if (!ptr) {
        new = malloc(size);
        
        if (!new) return NULL;
    } else {
        if (malloc_size(ptr) < size) { //malloc_usable_size
            new = malloc(size);
            
            if (!new) return NULL;

            mx_memcpy(new, ptr, malloc_size(ptr)); //malloc_usable_size
            free(ptr);
        } else new = ptr;
    }
    return new;
}
