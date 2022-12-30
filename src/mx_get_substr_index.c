#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!sub || !str) return -2;

    int index = 0;
    int sub_len = mx_strlen(sub);
    int str_len = mx_strlen(str);

    while (index + sub_len <= str_len) {
        if (!mx_strncmp(&str[index], sub, sub_len)) return index;
        index++;
    }
    return -1;
}
