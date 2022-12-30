#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if (!mx_strlen(needle)) return (char *) haystack;
    
    int len_s2 = mx_strlen(needle);
    int temp = mx_get_char_index(haystack, needle[0]);

    while (temp >= 0) {
        haystack += temp;
        char *haystack_copy = mx_strdup(haystack);

        if (mx_strncmp(haystack_copy, needle, len_s2) == 0) {
            mx_strdel(&haystack_copy);
            return (char *) haystack;
        }

        haystack++;
        temp = mx_get_char_index(haystack, needle[0]);
        mx_strdel(&haystack_copy);
    }
    return NULL;
}
