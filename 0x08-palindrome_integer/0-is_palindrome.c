#include "palindrome.h"
/**
 * is_palindrome - check if number palindrome
 *
 * @n:	number
 *
 * Return: 0 or 1
 */
int is_palindrome(unsigned long n)
{
	unsigned long new = n, num = 0, rev = 0;

	while (new != 0)
	{
		num = new % 10;
		rev = rev * 10 + num;
		new /= 10;
	}


	return (rev == n);
}

