#include "roman_date.h"
#include "roman_numerals.h"
#include <string.h>
#include <stdio.h>
#define is_leap_year(y) ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
int mlens[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char * months[] = {"Ian", "Feb", "Mar", "Apr", "Mai", "Iun", "Iul", "Aug", "Sep", "Oct", "Nov", "Dec"};

char * ides_str = "Id";
char * nones_str = "Non";
char * kal_str = "Kal";


bool roman_day (int d, int m, int y, char * buf, size_t size) {
	if (d < 1 || m < 0 || m > 11 || y < 1) return false;
	if (is_leap_year (y) && m == 1 && d >= 25) --d; //Romans don't know leap day, 24 Feb reckoned to last 48 hours instead
	if (d >= mlens[m]) return false;
	int ides = 13;
	if (m == 2 || m == 4 || m == 6 || m == 9) ides = 15;
	int nones = ides - 8;
	char * dstr;
	int diff;
	if (d == 1) {
		dstr = kal_str;
		diff = 1;
	}
	else if (d > ides) {
		dstr = kal_str;
		diff = mlens[m] - d + 2;
		m = (m + 1) % 12;
	}
	else if (d <= nones) {
		dstr = nones_str;
		diff = nones - d + 1;
	}
	else {
		dstr = ides_str;
		diff = ides - d + 1;
	}
	if (diff == 1) snprintf (buf, size, "%s. %s.", dstr, months[m]);
	else if (diff == 2) snprintf (buf, size, "prid. %s. %s", dstr, months[m]);
	else {
		char diffbuf[10];
		roman_numeral (diff, diffbuf, 10);
		snprintf (buf, size, "a.d. %s %s. %s.", diffbuf, dstr, months[m]);
	}
	return true;
}


