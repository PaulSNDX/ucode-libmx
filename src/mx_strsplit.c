#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s) return NULL;

    int i = 0;
    char **array = (char **) malloc((mx_count_words(s, c) + 1) * sizeof(char *));
    array[i] = NULL;

    while ((*s) && (*s != '\0')) {
        if (*s != c) {
            int element_len = 0;
            
            while (s[element_len] && s[element_len] != c) element_len++;
            
            array[i++] = mx_strndup(s, element_len);
            s += element_len;
        } else s++;
    }

    return array;
}
