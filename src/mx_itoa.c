#include "../inc/libmx.h"

static int mx_int_len(int number) {
    int len = 0;

    if (number < 0) {
        number *= -1;
        len++;
    }

    while (number > 0) {
        number /= 10;
        len++;
    }

    return len;
}

char *mx_itoa(int number) {
    char *ascii = NULL;
    
    if (number == -2147483648) ascii = "-2147483648";
    else if (number == 0) ascii = "0";
    else {
        int pow = number < 0 ? -1 : 1;
        int len = mx_int_len(number);
        ascii = mx_strnew(len);

        if (number < 0) ascii[--len] = '-';

        for (int i = number; i >= 10 || i <= -10; i /= 10) pow *= 10;

        while (pow != 0) {
            ascii[--len] = 48 + number / pow;
            number %= pow;
            pow /= 10;
        }

        mx_str_reverse(ascii);
    }
    return ascii;
}
