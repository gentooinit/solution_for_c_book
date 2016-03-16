/*
 * File name: check.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 34
 * Exercise 1-24. Write a program to check a C program for rudimentary syntax
 * errors like unbalanced parentheses, brackets and braces. Don't forget about
 * quotes, both single and double, escape sequences, and comments. (The program
 * is hard if you do it in full generality.)
 *
 */
#include <stdio.h>
#ifdef __USE_XOPEN2K8
#warning "getline() maybe conflicts with stdio.h, try to compile with -ansi or -std=c89/c90/c99."
#endif


#define MAX_LINE         1024
#define MAX_COLUMN       1024
#define MAX_RECORD       1024

#define NORMAL           0
#define ESCAPE           1
#define COMMENT_ENTER    2
#define COMMENT_EXIT     3
#define COMMENT_IN       4
#define COMMENT_CXX_IN   5
#define CHAR_CONST_OPEN  6
#define CHAR_CONST_CLOSE 7
#define STRING           8

struct line_record {
	int lineno;
	int columnno;
};

/* getline: read a line into s, return length, replace '\t' by a blank */
int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
			if (c == '\t')
				c = ' ';

			s[i] = c;
	}

	if (c == '\n') {
		s[i] = '\n';
		++i;
	}

	s[i] = '\0';
	return i;
}

int inc_lv(char x, char c, int lv,
		struct line_record *rec,
		int lineno, int columnno)
{
	if (x == c) {
		/* assume MAX_RECORD is enough */
		if (lv >= 0 && lv < MAX_RECORD) {
			rec[lv].lineno = lineno;
			rec[lv].columnno = columnno;
		}
		++lv;
	}

	return lv;
}

int dec_lv(char x, char c, int lv)
{
	if (x == c)
		--lv;

	return lv;
}

void report_error(char msg[], char line[], int lineno, int columnno)
{
	printf("%d:%d: %s\n", lineno, columnno, msg);
	printf(" %s", line);
	printf("%*c\n", columnno + 1, '^');
}

int main(void)
{
	char c;
	int i;
	int state_bak;
	int state;
	int lineno, columnno;
	int paren_lv;
	int bracket_lv;
	int brace_lv;
	char line[MAX_LINE][MAX_COLUMN];
	char *current_line;
	struct line_record paren_record[MAX_RECORD];
	struct line_record bracket_record[MAX_RECORD];
	struct line_record brace_record[MAX_RECORD];

	paren_lv = 0;
	bracket_lv = 0;
	brace_lv = 0;
	lineno = columnno = 0;
	state = NORMAL;
	while (getline(line[lineno], MAX_COLUMN) > 0) {
		current_line = line[lineno];

		++lineno;
		for (i = 0; (c = current_line[i]); ++i) {
			++columnno;

			if (c == '\n')
				columnno = 0;

			switch (state) {
			case NORMAL:
				state_bak = NORMAL;
				if (c == '/') {
					state = COMMENT_ENTER;
				} else if (c == '\\') {
					state = ESCAPE;
				} else if (c == '\'') {
					state = CHAR_CONST_OPEN;
				} else if (c == '"') {
					state = STRING;
				} else {
					paren_lv = inc_lv(c, '(', paren_lv,
							paren_record,
							lineno, columnno);
					paren_lv = dec_lv(c, ')', paren_lv);

					bracket_lv = inc_lv(c, '[', bracket_lv,
							bracket_record,
							lineno, columnno);
					bracket_lv = dec_lv(c, ']', bracket_lv);

					brace_lv = inc_lv(c, '{', brace_lv,
							brace_record,
							lineno, columnno);
					brace_lv = dec_lv(c, '}', brace_lv);

					if (paren_lv < 0) {
						report_error("Error: Unbalance ')'",
								current_line,
								lineno,
								columnno);

						/* Error recovery */
						paren_lv = 0;
					}

					if (bracket_lv < 0) {
						report_error("Error: Unbalance ']'",
								current_line,
								lineno,
								columnno);

						/* Error recovery */
						bracket_lv = 0;
					}

					if (brace_lv < 0) {
						report_error("Error: Unbalance '}'",
								current_line,
								lineno,
								columnno);

						/* Error recovery */
						brace_lv = 0;
					}
				}
				break;
			case ESCAPE:
				state = state_bak;
				break;
			case CHAR_CONST_OPEN:
				state_bak = CHAR_CONST_OPEN;

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
				break;
			case COMMENT_ENTER:
				if (c == '*')
					state = COMMENT_IN;
				else if (c == '/')
					state = COMMENT_CXX_IN;
				else
					state = NORMAL;
				break;
			case COMMENT_IN:
				if (c == '*')
					state = COMMENT_EXIT;
				break;
			case COMMENT_CXX_IN:
				if (c == '\n')
					state = NORMAL;
				break;
			case COMMENT_EXIT:
				if (c == '/')
					state = NORMAL;
				else
					state = COMMENT_IN;
				break;
			case STRING:
				state_bak = STRING;

				if (c == '\\')
					state = ESCAPE;
				else if (c == '"' || c == '\n')
					state = NORMAL;
				break;
			}
		}
	}

	while (paren_lv > 0) {
		--paren_lv;
		if (paren_lv >= MAX_RECORD)
			break;

		lineno = paren_record[paren_lv].lineno;
		columnno = paren_record[paren_lv].columnno;

		report_error("Error: Unbalance '('",
				line[lineno - 1],
				lineno, columnno);
	}

	while (bracket_lv > 0) {
		--bracket_lv;
		if (bracket_lv >= MAX_RECORD)
			break;

		lineno = paren_record[bracket_lv].lineno;
		columnno = paren_record[bracket_lv].columnno;

		report_error("Error: Unbalance '['",
				line[lineno - 1],
				lineno, columnno);
	}

	while (brace_lv > 0) {
		--brace_lv;
		if (brace_lv > MAX_RECORD)
			break;

		lineno = brace_record[brace_lv].lineno;
		columnno = brace_record[brace_lv].columnno;

		report_error("Error: Unbalance '{'",
				line[lineno - 1],
				lineno, columnno);
	}

	return 0;
} 

