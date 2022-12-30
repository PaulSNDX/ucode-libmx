#include "../inc/libmx.h"

void mx_printstr(const char *s) {
    if (s != NULL) write(1, s, mx_strlen(s));
}
