#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) return NULL;

    char *trimmed_str = mx_strtrim(str);

    if (mx_strlen(trimmed_str) <= 0) return mx_strnew(0);

    int len = mx_strlen(trimmed_str);
    char *copy = mx_strdup(trimmed_str);
    
    for (int i = 0; trimmed_str[i] != '\0'; i++) {
        if (mx_isspace(trimmed_str[i])) copy[i] = 32;
        else copy[i] = trimmed_str[i];
        
        if (mx_isspace(trimmed_str[i]) && mx_isspace(trimmed_str[i + 1])) len--;
    }

    char *new = mx_strnew(len);
    new[len] = '\0';

    for (int i = 0, j = 0; i < mx_strlen(trimmed_str); i++) {
        if (mx_isspace(trimmed_str[i]) && mx_isspace(trimmed_str[i + 1])) continue;
        new[j++] = copy[i];
    }

    mx_strdel(&copy);
    mx_strdel(&trimmed_str);
    return new;
}
