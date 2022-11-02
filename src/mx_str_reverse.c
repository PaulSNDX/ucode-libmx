#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    int len = mx_strlen(s);
    
    if (len > 1) {
        int centre = len % 2 == 0 ? len / 2 : (len - 1) / 2;

        for (int i = 0; i < centre; i++)
            mx_swap_char(&s[i], &s[len - i - 1]);
    }
}
