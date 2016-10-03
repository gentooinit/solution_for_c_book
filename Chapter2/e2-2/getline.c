/*
 * File name: getline.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 42
 * Exercise 2-2. Write a loop equivalent to the for loop above without using &&
 * or ||.
 *
 */
#include <stdio.h>
#ifdef __USE_XOPEN2K8
#warning "getline() maybe conflicts with stdio.h, try to compile with -ansi or -std=c89/c90/c99."
#endif

#define MAX_LENGTH 1000

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1; ++i) {
		c = getchar();

		if (c == '\n')
			break;

		if (c == EOF)
			break;

		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return i;
}

int main()
{
	char str[MAX_LENGTH];

	while (getline(str, MAX_LENGTH) != 0)
		printf("%s", str);

	return 0;
}

