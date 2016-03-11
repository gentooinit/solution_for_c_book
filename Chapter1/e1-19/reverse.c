/*
 * File name: reverse.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 31
 * Exercise 1-19. Write a function reverse(s) that reverse the character string
 * s. Use it to write a program that reverses its input a line at a time.
 *
 */
#include <stdio.h>
#ifdef __USE_XOPEN2K8
#warning "getline() maybe conflicts with stdio.h, try to compile with -ansi or -std=c89/c90/c99."
#endif

#define MAXLINE 128    /* maximum input line size */

/* Compile with -ansi option */
int getline(char line[], int maxline);
void reverse(char s[]);

/* Reverse the character of lines */
int main()
{
	char line[MAXLINE];    /* current input line */

	while (getline(line, MAXLINE) > 0) {
		reverse(line);
		printf("%s", line);
	}

	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
			s[i] = c;

	if (c == '\n') {
		s[i] = '\n';
		++i;
	}

	s[i] = '\0';
	return i;
}

void reverse(char s[])
{
	int i, j;
	char tmp;

	for (i = 0; s[i] != '\0' && s[i] != '\n'; ++i)
		;

	j = i - 1;
	for (i = 0; i < j; ++i, --j) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

