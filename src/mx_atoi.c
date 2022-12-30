#include "../inc/libmx.h"

int mx_atoi(const char *str) {
    int mult = 1;
    int result = 0;

    if (*str == '-' || *str == '+') {
        if (*str == '-') mult = -1;
        str++;
    }

    while(mx_isdigit(*str)) {
        result *= 10;
        result += (*str - 48) * mult;
        str++;
    }

    if (*str != '\0') return -1; // change for 0 in some cases

    return result;
}
