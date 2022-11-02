#include "../inc/libmx.h"

int mx_sqrt(int x) {
    if (x <= 0) return 0;
    
    int k = 1;

    while (k <= x / k) {
        if (k * k == x) return k;
        k++;
    }

    return 0;
}
