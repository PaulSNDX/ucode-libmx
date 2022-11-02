#include "../inc/libmx.h"

char *mx_strnew(const int size) {
    if (size < 0) return NULL;

    char *string = (char *) malloc((size + 1) * sizeof(char));
    
    for (int i = 0; i <= size; i++) string[i] = '\0';

    return string;
}
