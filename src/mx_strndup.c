#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *new_string = mx_strnew(n);
    return mx_strncpy(new_string, s1, n);
}
