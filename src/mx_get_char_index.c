#include "../inc/libmx.h"

int mx_get_char_index(const char *str, char c) {
    if (str == NULL) return -2;

    for (int i = 0; i < mx_strlen(str); i++)
        if (c == str[i]) return i;

    return -1;
}
