#define _XOPEN_SOURCE
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "roman_date.h"
#include "roman_numerals.h"

struct conf {
	bool cur_time;
	struct tm t_struct; //not used if cur_time = true
	bool christian;
};

void parse_args (struct conf * config, int argc, char * argv[]) {
	int c;
	char * tmp;
	while ((c = getopt (argc, argv, "cd:")) != -1) {
		switch (c){
			case 'd':
				tmp = strptime (optarg, "%d/%m/%Y", &config->t_struct);
				if (tmp == NULL || *tmp != 0) {
					fprintf (stderr, "%s is invalid data\n", optarg);
					exit (EXIT_FAILURE);
				}
				config->cur_time = false;
				break;
			case 'c':
				config->christian = true;
				break;
		}
	}
}

void fill_date (struct conf * c) {
	if (c->cur_time) {
		time_t t = time (NULL);
		c->t_struct = *localtime (&t);
	}
}

void print_day (struct conf * c) {
	int d = c->t_struct.tm_mday;
	int m = c->t_struct.tm_mon;
	int y = c->t_struct.tm_year + 1900;
	char buf[100];
	if (roman_day (d, m, y, buf, 100)){
		printf ("%s", buf);
	} else {
		printf ("Date %d/%d/%d is invalid\n", d, m, y);
		exit (EXIT_FAILURE);
	}
}

char * epoch[] = {"%s AUC", "%s p. Chr. n"};
void print_year (struct conf * c) {
	int y = c->t_struct.tm_year + 1900;
	if (!c->christian) y += 753; //Roman epoch
	int epoch_num = c->christian?1:0;
	char buf[100];
	if (roman_numeral (y, buf, 100) > 0) {
		printf (epoch[epoch_num], buf);
	}
	else {
		printf ("year unrecognized (val. %d)\n", c->christian?y:y - 753);
		exit (EXIT_FAILURE);
	}
}
int main (int argc, char * argv[]){
	struct conf config = {
		.cur_time = true,
		.christian = false,
	};
	parse_args (&config, argc, argv);
	fill_date (&config);
	print_day (&config);
	printf (", ");
	print_year (&config);
	printf ("\n");
	return EXIT_SUCCESS;
}
