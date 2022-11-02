#include "../inc/libmx.h"

bool mx_islower_hex(int c) {
    return (97 <= c && c <= 102) ? 1 : 0; // for hex a-f
}
