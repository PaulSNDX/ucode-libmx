#include "../inc/libmx.h"

char *mx_strchr(const char *s, int c) {
    while (*s != '\0') {
        if (*s == c) return (char *)s;
        s++;
    }
    return NULL;
}
