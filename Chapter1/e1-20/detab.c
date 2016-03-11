/*
 * File name: detab.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 34
 * Exercise 1-20. Write a program detab that in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
 * every n columns. Should n be a variable or a symbolic parameter?
 *
 * A: n shoube be a symbolic parameter.
 *
 */
#include <stdio.h>

#define NTAB 4
int main(void)
{
	char c;
	int count;

	count = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			count = 0;
		else if (c != '\t')
			++count;

		if (c == '\t') {
			for (; count < NTAB; ++count)
				putchar(' ');
		} else {
			putchar(c);
		}

		count %= NTAB;
	}

	return 0;
}

