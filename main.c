#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "roman_date.h"
#include "roman_numerals.h"

int main (int argc, char * argv[]){
	time_t t = time (NULL);
	struct tm t_struct = *localtime (&t);
	int d = t_struct.tm_mday;
	int m = t_struct.tm_mon;
	int y = t_struct.tm_year + 1900;
	char buf[100];
	if (roman_day (d, m, y, buf, 100)){
		printf ("%s, ", buf);
		if (roman_numeral (y + 753, buf, 100) > 0) {
			printf ("%s AUC\n", buf);
		}
		else {
			printf ("year unrecognized (val. %d)\n", y);
			return EXIT_FAILURE;
		}
	}
	else {
		printf ("Date %d/%d/%d is invalid\n", d, m, y);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
