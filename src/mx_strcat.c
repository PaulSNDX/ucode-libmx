#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int i = 0;
    int j = 0;
    
    while (i < mx_strlen(s1)) i++;
    
    while (j < mx_strlen(s2)) {
        s1[i] = s2[j];
        j++;
        i++;
    }
    
    s1[i] = '\0';   
    return s1;
}
