#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int i = mx_strlen(s1) - 1;
    int j = 0;
        
    while (j < mx_strlen(s2)) {
        s1[i] = s2[j];
        j++;
        i++;
    }
    
    s1[i] = '\0';   
    return s1;
}
