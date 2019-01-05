CFLAGS = -O2 -Wall

all: main.o roman_date.o roman_numerals.o
	$(CC) $(CFLAGS) main.o roman_date.o roman_numerals.o -o auc

clean:
	rm *.o
	rm auc
