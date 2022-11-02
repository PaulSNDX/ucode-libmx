#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int len_s2 = mx_strlen(needle);
    char temp[len_s2 + 1];
    temp[len_s2] = '\0';

    for (int i = 0; i < mx_strlen(haystack) - len_s2; i++) {
        for (int j = 0; j < len_s2; j++) temp[j] = haystack[j];
        if (mx_strncmp(temp, needle, len_s2) == 0) return (char *)haystack;
        haystack++;
    }
    return NULL;
}
