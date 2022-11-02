#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!sub || !str) return -2;

    int index = 0;
    int sub_len = mx_strlen(sub);
    char temp[sub_len];

    while (str[index] != '\0') {
        mx_strncpy(temp, str, sub_len);
        
        if (mx_strcmp(temp, sub) == 0) return index;
        
        index++;
        str++;
    }

    return -1;
}
