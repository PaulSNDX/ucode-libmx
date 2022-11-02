#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    unsigned char unicode_char[4];
    int size = 0;

    if (c < 0x80) unicode_char[size++] = ((c >> 0) & 0x7F) | 0x00;
    else {
        if (c < 0x0800) unicode_char[size++] = ((c >> 6) & 0x1F) | 0xC0;
        else {
            if (c < 0x010000) unicode_char[size++] = ((c >> 12) & 0x1F) | 0xE0;
            else if (c < 0x110000) {
                unicode_char[size++] = ((c >> 18) & 0x07) | 0xF0;
                unicode_char[size++] = ((c >> 12) & 0x3F) | 0x80;
            } else return;
            unicode_char[size++] = ((c >> 6) & 0x3F) | 0x80;
        }
        unicode_char[size++] = ((c >> 0) & 0x3F) | 0x80;
    }

    write(1, unicode_char, size);
}
