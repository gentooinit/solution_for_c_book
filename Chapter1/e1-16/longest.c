/*
 * File name: longest.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 30
 * Exercise 1-16. Revise the main routine of the longest-line program so it will
 * correctly print the length of arbitrarily long input lines, and as much as
 * possible of the text.
 *
 */
#include <stdio.h>
#ifdef __USE_XOPEN2K8
#warning "getline() maybe conflicts with stdio.h, try to compile with -ansi or -std=c89/c90/c99."
#endif

#include <string.h>
#define MAXLINE 80    /* maximum input line size */

/* Compile with -ansi option */
int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
	int len;        /* current line length */
	int prev_len;   /* previous line length */
	int max;        /* maximum length seen so far */
	char line[MAXLINE];    /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	char longest_possibly[MAXLINE];  /*  maybe the longest line */

	max = 0;
	prev_len = 0;
	while ((len = getline(line, MAXLINE)) > 0) {
		if (line[strlen(line) - 1] == '\n') {
			/* a completed line */
			len += prev_len;

			if (len > max) {
				max = len;

				/* Now we sure the longest_possibly is the longest line */
				if (prev_len > 0)
					copy(longest, longest_possibly);
				else
					copy(longest, line);
			}

			prev_len = 0;
		} else {
			/* a parted line */

			/* do not copy if there is a parted line before */
			if (prev_len == 0)
				copy(longest_possibly, line);

			prev_len += len;
		}
	}

	/* there was a line */
	if (max > 0) {
		printf("%s", longest);

		if (longest[strlen(longest) - 1] != '\n')
			printf("%c", '\n');
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
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

