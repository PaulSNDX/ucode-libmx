#include "../inc/libmx.h"

void mx_printint(int n) {
    int pow = 1;

    if (n < 0) {
        mx_printchar('-');
        pow = -1;
    }

    for (int i = n; i >= 10 || i <= -10; i /= 10) pow *= 10;
    
    while (pow != 0) {
        mx_printchar(48 + n / pow);
        n %= pow;
        pow /= 10;
    }
}
