#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace) return NULL;

    int k = mx_count_substr(str, sub);
    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);
    int new_size = mx_strlen(str) + k * (replace_len - sub_len);
    char *new_str = mx_strnew(new_size);
    
    for (int index = 0; *str != '\0';) {
        if (k-- != 0 && mx_strncmp(str, sub, sub_len) == 0) {
            for (int i = 0; i < replace_len;)
                new_str[index++] = replace[i++];

            str += sub_len - 1;
        } else new_str[index++] = *str;
        
        str++;
    }
    return new_str;
}
