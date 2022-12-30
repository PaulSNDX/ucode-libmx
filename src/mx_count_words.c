#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter) {
    if (!str) return -1;
    
    int len = mx_strlen(str);
    
    if (!len) return 0;
    if (mx_get_char_index(str, delimiter) < 0) return 1;

    bool only_delimiters = true;
    int words = 0;
    int c = 0;

    if (str[c++] != delimiter) {
        words++;
        only_delimiters = false;
    }

    for (int i = 1; only_delimiters && i < len; i++)
        if (str[i] != delimiter)
            only_delimiters = false;

    if (only_delimiters) return 0;
    if (len == 2) return 1;
    
    while (str[c + 1] != '\0')
        if (str[c++] == delimiter && str[c] != delimiter) words++;

    return words;
}
