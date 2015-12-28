/*
 * File name: blanks.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 20
 * Exercise 1-8. Write a program to copy its input to its output, replacing each
 * string of one or more blanks by a single blank.
 *
 */
/* EOF defined in <stdio.h> */
#include <stdio.h>

int main()
{
	int c;
	int first_blank;

	first_blank = 0;
	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			first_blank = 0;
			putchar(c);
		} else if (!first_blank) {
			/* Mark the first blank and put it */
			first_blank = 1;
			putchar(c);
		}
	}

	return 0;
}

