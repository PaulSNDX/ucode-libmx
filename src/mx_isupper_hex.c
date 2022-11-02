#include "../inc/libmx.h"

bool mx_isupper_hex(int c) {
    return (65 <= c && c <= 70) ? 1 : 0; // for hex A-F
}
