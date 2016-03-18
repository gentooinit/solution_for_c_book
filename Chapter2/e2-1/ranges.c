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

#define MIN_SIGNED(x) (1 << (8 * sizeof(x) - 1))
#define MAX_SIGNED(x) (~MIN_SIGNED(x))
#define MIN_UNSIGNED(x) 0
#define MAX_UNSIGNED(x) (~MIN_UNSIGNED(x))

int main()
{
	printf("signed char: %hhd~%hhd\n", MIN_SIGNED(signed char), MAX_SIGNED(signed char));
	printf("unsigned char: %hhu~%hhu\n", MIN_UNSIGNED(unsigned char), MAX_UNSIGNED(unsigned char));
	printf("signed short: %hd~%hd\n", MIN_SIGNED(signed short), MAX_SIGNED(signed short));
	printf("unsigned short: %hu~%hu\n", MIN_UNSIGNED(unsigned short), MAX_UNSIGNED(unsigned short));
	printf("signed int: %d~%d\n", MIN_SIGNED(signed int), MAX_SIGNED(signed int));
	printf("unsigned int: %u~%u\n", MIN_UNSIGNED(unsigned int), MAX_UNSIGNED(unsigned int));
	printf("signed long: %ld~%ld\n", MIN_SIGNED(signed long), MAX_SIGNED(signed long));
	printf("unsigned long: %lu~%lu\n", MIN_UNSIGNED(unsigned long), MAX_UNSIGNED(unsigned long));

	//TODO: float

	return 0;
}

