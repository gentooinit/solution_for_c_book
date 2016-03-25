/*
 * File name: ranges.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 36
 * Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 *
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

#define MAX_UNSIGNED(x) ((x)~MIN_UNSIGNED(x))
#define MIN_UNSIGNED(x) ((x)0)
#define MAX_SIGNED(x) ((unsigned x)~0 >> 1)
#define MIN_SIGNED(x) (MAX_SIGNED(x) + 1)

int main()
{
	printf("signed char: %hhd~%hhd\n", MIN_SIGNED(char), MAX_SIGNED(char));
	printf("unsigned char: %hhu~%hhu\n", MIN_UNSIGNED(unsigned char), MAX_UNSIGNED(unsigned char));
	printf("signed short: %hd~%hd\n", MIN_SIGNED(short), MAX_SIGNED(short));
	printf("unsigned short: %hu~%hu\n", MIN_UNSIGNED(unsigned short), MAX_UNSIGNED(unsigned short));
	printf("signed int: %d~%d\n", MIN_SIGNED(int), MAX_SIGNED(int));
	printf("unsigned int: %u~%u\n", MIN_UNSIGNED(unsigned int), MAX_UNSIGNED(unsigned int));
	printf("signed long: %ld~%ld\n", MIN_SIGNED(long), MAX_SIGNED(long));
	printf("unsigned long: %lu~%lu\n", MIN_UNSIGNED(unsigned long), MAX_UNSIGNED(unsigned long));

	
	/* from header */
	printf("--------------------from header--------------------\n");
	printf("signed char: %hhd~%hhd\n", SCHAR_MIN, SCHAR_MAX);
	printf("unsigned char: %hhu~%hhu\n", 0, UCHAR_MAX);
	printf("signed short: %hd~%hd\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short: %hu~%hu\n", 0, USHRT_MAX);
	printf("signed int: %d~%d\n", INT_MIN, INT_MAX);
	printf("unsigned int: %u~%u\n", 0, UINT_MAX);
	printf("signed long: %ld~%ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long: %lu~%lu\n", 0, ULONG_MAX);

	printf("float: %g~%g\n", FLT_MIN, FLT_MAX);
	printf("double: %g~%g\n", DBL_MIN, DBL_MAX);
	return 0;
}
