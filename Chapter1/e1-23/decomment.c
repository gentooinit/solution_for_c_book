/*
 * File name: decomment.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 34
 * Exercise 1-23. Write a program to remove all comments from a C program. Don't
 * forget to handle quoted strings and character constants properly. C comments
 * do not nest.
 *
 */
#include <stdio.h>

#define NORMAL           0
#define ESCAPE           1
#define COMMENT_ENTER    2
#define COMMENT_EXIT     3
#define COMMENT_IN       4
#define COMMENT_CXX_IN   5
#define CHAR_CONST_OPEN  6
#define CHAR_CONST_CLOSE 7
#define STRING           8

int main(void)
{
	char c;
	int state_bak;
	int state;

	state = NORMAL;
	while ((c = getchar()) != EOF) {
		switch (state) {
		case NORMAL:
			state_bak = NORMAL;
			if (c == '/') {
				state = COMMENT_ENTER;
			} else if (c == '\\') {
				state = ESCAPE;
				putchar(c);
			} else if (c == '\'') {
				state = CHAR_CONST_OPEN;
				putchar(c);
			} else if (c == '"') {
				state = STRING;
				putchar(c);
			} else {
				putchar(c);
			}
			break;
		case ESCAPE:
			state = state_bak;
			putchar(c);
			break;
		case CHAR_CONST_OPEN:
			state_bak = CHAR_CONST_OPEN;
			putchar(c);

			if (c == '\'')
				state = NORMAL;
			else if (c == '\\')
				state = ESCAPE;
			else
				state = CHAR_CONST_CLOSE;
			break;
		case CHAR_CONST_CLOSE:
			/*
			 * try to match a '\'',
			 * but no matter what c is,
			 * state switchs to NORMAL
			 */
			state = NORMAL;
			putchar(c);
			break;
		case COMMENT_ENTER:
			if (c == '*') {
				state = COMMENT_IN;
			} else if (c == '/') {
				state = COMMENT_CXX_IN;
			} else {
				state = NORMAL;
				putchar('/');
				putchar(c);
			}
			break;
		case COMMENT_IN:
			if (c == '*')
				state = COMMENT_EXIT;
			break;
		case COMMENT_CXX_IN:
			if (c == '\n') {
				state = NORMAL;
				putchar(c);
			}
			break;
		case COMMENT_EXIT:
			if (c == '/')
				state = NORMAL;
			else
				state = COMMENT_IN;
			break;
		case STRING:
			state_bak = STRING;
			putchar(c);

			if (c == '\\')
				state = ESCAPE;
			else if (c == '"' || c == '\n')
				state = NORMAL;
			break;
		}
	}

	return 0;
} 

