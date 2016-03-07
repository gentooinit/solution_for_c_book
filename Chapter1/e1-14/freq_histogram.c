/*
 * File name: freq_histogram.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 24
 * Exercise 1-14. Write a program to print a histogram of the frequencies of
 * different characters in its input.
 *
 */
#include <stdio.h>
#include <ctype.h>

#define CHAR_NUM 256

int main()
{
	int i, j;
	int c;
	int histogram[CHAR_NUM];

	for (i = 0; i < CHAR_NUM; ++i)
		histogram[i] = 0;

	while ((c = getchar()) != EOF)
		++histogram[c];

	/* Histogram */
	printf("Characters frequencies histogram\n");
	printf("--------------------------------\n");
	for (i = 0; i < CHAR_NUM; ++i) {
		if (histogram[i]) {
			if (isprint(i))
				printf("'%c'(\\x%02x): ", i, i);
			else
				printf("' '(\\x%02x): ", i);

			for (j = 1; j <= histogram[i]; ++j)
				printf("=");
			printf("\n");
		}
	}

	return 0;
}

