#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c) {
    if (!s || !c) return NULL;

    int current = 0;
    int amount_of_words = mx_count_words(s, c);
    char **array = (char **) malloc((amount_of_words + 1) * sizeof(char *));
    array[amount_of_words] = NULL;
    
    while (*s) {
        int len = 0;

        if (!current && *s != c) while (s[len] != c && s[len] != '\0') len++;
        else if (*s == c) while (s[len + 1] != c && s[len + 1] != '\0') len++;
        
        char *new_element = mx_strndup(s, len);
        s += len == 0 ? 1 : len;

        if (new_element) array[current++] = new_element;
    }
    return array;
}
