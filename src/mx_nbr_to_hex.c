#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int len = 1;

    for (unsigned long i = nbr; i >= 16; i /= 16) len++;

    char *hex = mx_strnew(len);

    for (int j = len; j > 0; j--) {
        char temp = nbr % 16 + 48;
        nbr /= 16;
        hex[j - 1] = (48 <= temp && temp <= 57) ? temp : temp + 39;
    }

    return hex;
}
