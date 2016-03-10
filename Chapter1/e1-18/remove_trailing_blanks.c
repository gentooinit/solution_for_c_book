/*
 * File name: remove_trailing_blanks.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 31
 * Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines.
 *
 */
#include <stdio.h>
#ifdef __USE_XOPEN2K8
#warning "getline() maybe conflicts with stdio.h, try to compile with -ansi or -std=c89/c90/c99."
#endif

#include <ctype.h>
#define MAXLINE 128    /* maximum input line size */

/* Compile with -ansi option */
int getline(char line[], int maxline);
void remove_trailing(char s[]);

/* print longer than 80 characters input line */
int main()
{
	int len;        /* current line length */
	char line[MAXLINE];    /* current input line */

	while ((len = getline(line, MAXLINE)) > 0) {
		remove_trailing(line);
		if (line[0] != '\0')
			printf("%s\n", line);
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

void remove_trailing(char s[])
{
	char *end;

	end = s;
	while (*s) {
		/*
		 * The question demands to remove trailing blanks,
		 * but I think '\n', '\v', '\f', '\r' are also included.
		 * 
		 */
		if (!isspace(*s))
			end += s - end;

		++s;
	}

	/* remove entirely blank line */
	if (!isspace(*end))
		++end;

	*end = '\0';
}

