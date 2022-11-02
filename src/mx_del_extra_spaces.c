#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) return NULL;

    str = mx_strtrim(str);
    int len = mx_strlen(str);
    
    for (int i = 0; str[i] != '\0'; i++)
        if (mx_isspace(str[i]) && mx_isspace(str[i + 1])) len--;

    char *new = mx_strnew(len);
    new[len] = '\0';

    for (int i = 0, j = 0; i < mx_strlen(str); i++) {
        if (mx_isspace(str[i]) && mx_isspace(str[i + 1])) continue;
        new[j++] = str[i];
    }

    return new;
}
