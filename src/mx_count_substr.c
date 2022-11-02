#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) return -1;

    int count = 0;
    int index = 0;
    int temp = mx_get_substr_index(str, sub);

    while (temp >= 0) {
        count++;
        index += temp + mx_strlen(sub);
        
        if (index + mx_strlen(sub) < mx_strlen(str))
            temp = mx_get_substr_index(&str[index], sub);
        else break;
    }
    return count;
}
