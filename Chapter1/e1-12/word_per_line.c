/*
 * File name: word_per_line.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 21
 * Exercise 1-12. Write a program that prints its input one word per line.
 *
 */
/* EOF defined in <stdio.h> */
#include <stdio.h>

#define IN  1    /* inside a word */
#define OUT 0    /* outside a word */

int main()
{
	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN)
				putchar('\n');
			state = OUT;
		} else {
			putchar(c);
			state = IN;
		}
	}
	
	if (state == IN)
		putchar('\n');

	return 0;
}

