#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    for (int i = 0; i < len; i++) {
        if (src[i] == '\0') {
            while (i < mx_strlen(dst)) dst[i++] = '\0';
            break;
        } else dst[i] = src[i];
    }
    // dst[len] = '\0';
    // is commented BECAUSE:
    // DESCRIPTION
    //  The stpcpy() and strcpy() functions copy the string src to dst (including
    //  the terminating ‘\0’ character.)

    //  The stpncpy() and strncpy() functions copy at most len characters from
    //  src into dst.  If src is less than len characters long, the remainder of
    //  dst is filled with ‘\0’ characters.  Otherwise, dst is not terminated.

    //  The source and destination strings should not overlap, as the behavior is
    //  undefined.
    return dst;
}
