/*
 * File name: len_histogram.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 24
 * Exercise 1-13. Write a program to print a histogram of the lengths of words
 * in its input. It is easy to draw the histogram with the bars horizontal; a 
 * vertical orientation is more challenging.
 *
 */
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 128
#define IN  1                 /* inside a word */
#define OUT 0                 /* outside a word */

void inc_histogram(int hisgram[], int count)
{
	if (count <= MAX_WORD_LEN)
		++hisgram[count];
	else
		printf("Please incrase MAX_WORD_LEN at least to %d\n", count);
}

int decimal_width(int n)
{
	int i;

	for (i = 1; n /= 10; ++i)
		;

	return i;
}


int main()
{
	int i, j;
	int c, state;
	int counter;
	int max;
	int width, len;
	int buf[MAX_WORD_LEN];
	/*
	 * Dirty hacks.
	 * Cause I don't need to count the zero length word and I'm a miser.
	 * But there is one more varible(a pointer, maybe 4 bytes on 32-bit OS
	 * and 8 bytes on 64-bit) I needed to use. I pray it would be allocated
	 * in registers.
	 */
	int *histogram = &buf[-1];

	for (i = 1; i <= MAX_WORD_LEN; ++i)
		histogram[i] = 0;

	counter = 0;
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN)
				inc_histogram(histogram, counter);

			counter = 0;
			state = OUT;
		} else {
			++counter;
			state = IN;
		}
	}

	/* Count the last word */
	if (state == IN)
		inc_histogram(histogram, counter);


	/*
	 * Calcuate the max lengths of words
	 * For the width of printf()
	 */ 
	for (i = MAX_WORD_LEN; i >= 1; --i) {
		if (histogram[i]) {
			len = i;
			break;
		}
	}
	width = decimal_width(len);

	/* Horizontal histogram */
	printf("Word length horizontal histogram\n");
	printf("--------------------------------\n");
	for (i = 1; i <= MAX_WORD_LEN; ++i) {
		if (histogram[i]) {
			printf("%*d: ", width, i);

			for (j = 1; j <= histogram[i]; ++j)
				printf("=");
			printf("\n");
		}
	}

	printf("\n");

	/* Vertical histogram */
	max = 0;
	for (i = 1; i <= MAX_WORD_LEN; ++i) {
		if (max < histogram[i])
			max = histogram[i];
	}

	printf("Word length vertical histogram\n");
	printf("------------------------------\n");
	for (i = max; i >= 1; --i) {
		for (j = 1; j <= MAX_WORD_LEN; ++j) {
			if (histogram[j]) {
				if (histogram[j] >= i)
					printf("%-*c ", width, '*');
				else
					printf("%-*c ", width, ' ');
			}
		}
		printf("\n");
	}

	for (i = 1; i <= MAX_WORD_LEN; ++i) {
		if (histogram[i]) {
			len = decimal_width(i);
			/* C99 VLA, I really don't want to use it. */
			char str[len + 1];

			memset(str, '-', len);
			str[len] = '\0';
			
			printf("%-*s ", width, str);
		}
	}
	printf("\n");

	for (i = 1; i <= MAX_WORD_LEN; ++i) {
		if (histogram[i])
			printf("%-*d ", width, i);
	}
	printf("\n");

	return 0;
}

