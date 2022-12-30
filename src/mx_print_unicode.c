#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
	if (c < 0x80) {
		char bytes[1];
		bytes[0] = (c >> 0 & 0x7F) | 0x00;
		write(1, bytes, 1);
	} else if (c < 0x0800) {
		char bytes[2];
		bytes[0] = (c >> 6 & 0x1F) | 0xC0;
		bytes[1] = (c >> 0 & 0x3F) | 0x80;
		write(1, bytes, 2);
	} else if (c < 0x010000) {
		char bytes[3];
		bytes[0] = (c >> 12 & 0x0F) | 0xE0;
		bytes[1] = (c >> 6 & 0x3F) | 0x80;
		bytes[2] = (c >> 0 & 0x3F) | 0x80;
		write(1, bytes, 3);
	} else if (c < 0x110000) {
		char bytes[4];
		bytes[0] = (c >> 18 & 0x07) | 0xF0;
		bytes[1] = (c >> 12 & 0x3F) | 0x80;
		bytes[2] = (c >> 6 & 0x3F) | 0x80;
		bytes[3] = (c >> 0 & 0x3F) | 0x80;
		write(1, bytes, 4);
	}
}
