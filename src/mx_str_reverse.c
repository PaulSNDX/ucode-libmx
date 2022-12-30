#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    if (s == NULL) return;
        
    int len = mx_strlen(s);
    
    if (len <= 1) return;

    int centre = (len - (len % 2 == 0 ? 0 : 1)) / 2;

    for (int i = 0; i < centre; i++)
        mx_swap_char(&s[i], &s[len - 1 - i]);
}
