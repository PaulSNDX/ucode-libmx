#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL)
        return NULL;
    
    int count = mx_count_substr(str, sub);
    int len = mx_strlen(str) + count * (mx_strlen(replace) - mx_strlen(sub));
    char *s = mx_strnew(len);

    if (count <= 0) return (char *) str;

    for (int i = 0; *str != '\0'; i++) {
        if (mx_strncmp(str, sub, mx_strlen(sub)) == 0) {
            for (int j = 0; j < mx_strlen(replace); j++)
                s[i++] = replace[j];
            
            str += mx_strlen(sub);
            --i;
        } 
        else {
            s[i] = *str;
            str++;
        }
    }
    return s; 
}
