/*
 * File name: getchar.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 17
 * Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
 *
 */
#include <stdio.h>

int main()
{
	/* 
	 * First things first, we discuss line buffered.
	 * In line buffered mode, \n key emits '\n' and then 
	 * flush the input buffer.
	 *
	 * On Linux, Ctrl+D flush the input buffer, if there is no
	 * character in buffer, it considered reach the EOF.
	 *
	 * On Windows, Ctrl+Z seems not to flush the input buffer(I'm not
	 * sure about it).
	 * 
	 *
	 * In English:
	 * On Linux, Ctrl+D at the beginning of line emits a EOF.
	 * On Windows, Ctrl+Z at the beginning of line, then hit ENTER, 
	 * that emits a EOF.
	 *
	 * Press Ctrl+C to kill the process.
	 */
	while (1)
		printf("%d\n", getchar() != EOF);

	return 0;
}

