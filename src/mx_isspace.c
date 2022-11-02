#include "../inc/libmx.h"

bool mx_isspace(char c) {
	return c == ' '
	    || c == '\n'
	    || c == '\t'
	    || c == '\v'
	    || c == '\f'
	    || c == '\r' ? true : false;
}
