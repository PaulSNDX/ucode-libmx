#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) return NULL;
    
    int end_index = 0;
    int start_index = -1;
    int len = mx_strlen(str);
    int temp = len;

    while (mx_isspace(str[++start_index]));
    while (mx_isspace(str[--temp])) end_index++;

    int new_size = len - (start_index + end_index);

    if (new_size <= 0) return mx_strnew(0);
    return mx_strndup(&str[start_index], new_size);
}
