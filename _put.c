#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * puthex - prints hexadecimal
 * @s: format string
 * @ap: variadic arguments
 * Return: integer
 */
int puthex(const char *s, va_list ap)
{
	unsigned int un;
	int d;
	int i;
	int dg;

	d = 1;

	if (*s == 'x')
	{
		un = va_arg(ap, unsigned int);
		while (un >= 16)
		{
			d++;
			un /= 16;
		}
		un = va_arg(ap, unsigned int);
		char arr[d + 1];

		for (i = d - 1; i >= 0; i--)
		{
			dg = un % 16;
			if (dg < 10)
			{
				arr[i] = '0' + dg;
			}
			else
			{
				arr[i] = 'a' + (dg - 10);
			}
			un /= 16;
		}
		arr[d] = '\0';
		for (i = 0; i <= d; i++)
		{
			putchar(arr[i]);
		}
	}
	return (d);
}
/**
 * putHEX - same as puthex
 * @s: format string
 * @ap: variadic arguments
 * Return: int
 */
int putHEX(const char *s, va_list ap)
{
	unsigned int un;
	int d;
	int i;
	int dg;
	
	d = 1;
	un = va_arg(ap, unsigned int);
	while (un >= 16)
	{
		d++;
		un /= 16;
	}
	un = va_arg(ap, unsigned int);
	char arr[d + 1];

	for (i = d - 1; i >= 0; i--)
	{
		dg = un % 16;
		if (dg < 10)
		{
			arr[i] = '0' + dg;
		}
		else
		{
			arr[i] = 'A' + (dg - 10);
		}
		un /= 16;
	}
	arr[d] = '\0';
	for (i = 0; i <= d; i++)
	{
		putchar(arr[i]);
	}
	return (d);
}
