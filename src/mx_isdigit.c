#include "../inc/libmx.h"

bool mx_isdigit(int c) {
    return (48 <= c && c <= 57) ? 1 : 0;
}
