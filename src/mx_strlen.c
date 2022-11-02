#include "../inc/libmx.h"

int mx_strlen(const char *str) {
    int count = 0;
    
    while (*str != '\0') {
        str++;
        count++;
    }
    return count;
}
