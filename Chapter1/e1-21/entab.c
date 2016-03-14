/*
 * File name: entab.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 34
 * Exercise 1-21. Write a program entab that replace strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab. When either a tab or a single blank would suffice to
 * a tab stop, which should be given preference?
 *
 * A: a single blank should be given preference.
 *
 */
#include <stdio.h>

#define NTAB 4

int main(void)
{
	char c;
	int count;
	int blank_count;

	count = 0;
	blank_count = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			count = 0;
			blank_count = 0;
		} else if (c != '\t') {
			++count;
		}

		if (c == ' ')
			++blank_count;

		if (c == ' ' && count == NTAB || c == '\t') {
			if (blank_count == 1)
				putchar(' ');
			else
				putchar('\t');

			count = 0;
			blank_count = 0;
		} else if (c != ' ') {
			for (; blank_count > 0; --blank_count)
				putchar(' ');

			putchar(c);
		}
		
		count %= NTAB;
	}

	/* tail blanks less than NTAB */
	for (; blank_count > 0; --blank_count)
		putchar(' ');

	return 0;
}

