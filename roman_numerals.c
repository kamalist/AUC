#include "roman_numerals.h"
#include <string.h>
#define NUMERALS_CNT 13
int digits[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
char *dig_str[] = {"M", "CM", "D", "CD", "C", "XC", 
                  "L", "XL", "X", "IX", "V", "IV", "I"};

int roman_numeral (int num, char * to, size_t size){
	if (num < 1) return E_NONPOSITIVE;
	unsigned int chars = 0, cur_nmrl = 0;
	while (num > 0) {
		if (num >= digits[cur_nmrl]) {
			num -= digits[cur_nmrl];
			int len = strlen (dig_str[cur_nmrl]);
			if (chars + len >= size - 1) return E_SMALLBUF;
			strcpy (to + chars, dig_str[cur_nmrl]);
			chars += len;
		}
		else {
			++cur_nmrl;
		}
	}
	to[chars] = 0;
	return chars;
}
