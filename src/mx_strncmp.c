#include "../inc/libmx.h"

int mx_strncmp(const char *s1, const char *s2, int n) {
    int i = 0;

    while (i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) i++;

    return (i == 0 ? s1[i] == s2[i] : s1[i - 1] == s2[i - 1]) ? 0 : s1[i - 1] - s2[i - 1];
}

// or
// int mx_strncmp(const char *s1, const char *s2, int n) {
//     int i = -1;
//     while (++i < n) if (s1[i] != s2[i]) return s1[i] - s2[i];
//     return 0;
//}
