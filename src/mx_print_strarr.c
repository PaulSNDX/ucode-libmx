#include "../inc/libmx.h"

static int mx_str_arr_len(char **str) {
    int count = 0;
    
    while (*str != NULL) {
        str++;
        count++;
    }

    return count;
}

void mx_print_strarr(char **arr, const char *delim) {
    if (arr != NULL && delim != NULL) {
        int elements = mx_str_arr_len(arr);
        
        for (int i = 0; i < elements; i++) {
            mx_printstr(arr[i]);
            if (elements != i + 1) write(1, delim, mx_strlen(delim));
        }
        
        mx_printchar('\n');
    }
}
