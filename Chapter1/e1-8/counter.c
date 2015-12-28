/*
 * File name: counter.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 20
 * Exercise 1-8. Write a program to count blanks, tabs, and newlines.
 *
 */
/* EOF defined in <stdio.h> */
#include <stdio.h>

int main()
{
	int c;
	int blank_cnt;
	int tab_cnt;
	int newline_cnt;

	blank_cnt = 0;
	tab_cnt = 0;
	newline_cnt = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++blank_cnt;
		else if (c == '\t')
			++tab_cnt;
		else if (c == '\n')
			++newline_cnt;
	}

	printf("blanks: %d, tabs: %d, newlines: %d\n",
		blank_cnt, tab_cnt, newline_cnt);

	return 0;
}

