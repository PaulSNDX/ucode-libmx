#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter) {
    int words = 0, c = 0;

    if (str[c] != '\0' && str[c] != delimiter) words++;

    while (str[c + 1] != '\0') {
        if (str[c] == delimiter && str[c + 1] != delimiter) words++;
        c++;
    }
    return words;
}
