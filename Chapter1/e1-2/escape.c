/*
 * File name: escape.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 8
 * Exercise 1-2. Experiment to find out what happens when
 * printf's argument string contains \c, where c is some character
 * not listed above.
 *
 */
#include <stdio.h>

int main()
{
	/*
	 * Refer to Page 193, the following escape sequences may be used.
	 */

	printf("NOTE:\n");
	printf("<start> is the start of escape sequences\n");
	printf("<end> is the end of escape sequences\n\n");

	/* \n, \t, \b, \", \\ are listed above the Exercise 1-2 */
	printf("Newline(NL/LF):<start>\n<end>\n");
	printf("Horizontal tab(HT):<start>\t<end>\n");
	printf("Vertical tab(VT):<start>\v<end>\n");
	printf("Backspace(BS):<start>\b<end>\n");
	printf("Carriage return(CR):<start>\r<end>\n");
	printf("Formfeed(FF):<start>\f<end>\n");
	printf("Audible alert(BEL):<start>\a<end>\n");

	/* printable characters */
	printf("backslash:<start>\\<end>\n");
	printf("question mark:<start>\?<end>\n");
	printf("single quote:<start>\'<end>\n");
	printf("double quote:<start>\"<end>\n");

	/* More than single \c character, use \ooo and \xhh to print 'A' */
	printf("octal number:<start>\101<end>\n");
	printf("hex number:<start>\x41<end>\n");
	printf("NUL(special \\ooo):<start>\0<end>\n");
	/*                                ^^ printf ends */

	printf("\n");

	return 0;
}

