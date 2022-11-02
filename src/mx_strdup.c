#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    char *new_string = mx_strnew(mx_strlen(str));
    return mx_strcpy(new_string, str);
}
