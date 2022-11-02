#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex == NULL) return 0;

    int digit;
    unsigned long nbr = 0;

    for (int i = 0; hex[i] != '\0';) {
        char symbol = hex[i++];

        if (mx_isdigit(symbol)) digit = symbol - 48;
        else if (mx_islower_hex(symbol)) digit = symbol - 87;
        else if (mx_isupper_hex(symbol)) digit = symbol - 55;
        else return 0;

        nbr = nbr * 16 + digit;
    }

    return nbr;
}
