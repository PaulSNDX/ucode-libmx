#include "../inc/libmx.h"

void mx_swap_str(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}
