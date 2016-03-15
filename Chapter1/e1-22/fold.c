/*
 * File name: fold.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 34
 * Exercise 1-22. Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 *
 */
#include <stdio.h>

#define WRAP_COLUMN 40
#define MAX_WORD WRAP_COLUMN
#define MAX_BLANKS WRAP_COLUMN

#define NTAB 8

void print_array(char s[], int len)
{
	while (len--)
		putchar(*s++);
}

int main(void)
{
	char c;
	char word[MAX_WORD];
	char blanks[MAX_BLANKS];
	int word_len, blanks_len;
	int column;
	int long_word;            /* very long line flag */

	column = 0;
	word_len = 0;
	blanks_len = 0;
	long_word = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			print_array(blanks, blanks_len);
			print_array(word, word_len);
			putchar(c);
			column = 0;
			word_len = 0;
			blanks_len = 0;
			long_word = 0;
		} else if (c == ' ' || c == '\t') {
			if (c == ' ')
				++column;
			else
				column += NTAB - column % NTAB;

			if (blanks_len < MAX_BLANKS)
				blanks[blanks_len++] = c;

			print_array(word, word_len);
			word_len = 0;
			long_word = 0;
		} else {
			++column;
			word[word_len++] = c;

			if (column < WRAP_COLUMN) {
				print_array(blanks, blanks_len);
				blanks_len = 0;
			} else {
				if (word_len < WRAP_COLUMN) {
					if (!long_word) {
						putchar('\n');
						column = word_len;
					}
				} else {
					print_array(word, word_len);
					word_len = 0;
					long_word = 1;
				}
				
				/* give up the tail blanks */
				blanks_len = 0;
			}
		}
	}

	print_array(blanks, blanks_len);
	print_array(word, word_len);

	return 0;
}

