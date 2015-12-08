/*
 * File name: temperature.c
 *
 * A solution to K&R The C Programming Language:
 *
 * Page 13
 * Exercise 1-4. Write a program to print the correspoding
 * Celsius to Fahrenheit table.
 *
 */
#include <stdio.h>

/* print Celsius-Fahrenheit table
    for celsius = 0, 20, ..., 300; floating-point version */
int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;        /* lower limit of temperature table */
	upper = 300;      /* upper limit */
	step = 20;        /* step size */

	printf("Celsius Fahrenheit\n");
	printf("------------------\n");

	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0 / 5.0) * celsius + 32.0;
		printf("%7.0f %10.1f\n", celsius, fahr);
		celsius = celsius + step;
	}

	return 0;
}

