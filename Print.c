#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - custom printf
 * @format: format string
 * Return: integer
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int n;

	n = 0;

	if (format == NULL)
		return (n);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '\\')
		{
			back(format);
			n++;
			format++;
		}
		else if (*format == '%')
		{
			n += mod(format, ap);
			format++;
		}
		else
		{
			putchar(*format);
			n++;
		}
		format++;
	}
	va_end(ap);
	return (n);
}
/**
 * mod - handles modulos
 * @s: format string
 * @ap: variadic arguments
 * Return: integer
 */
int mod(const char *s, va_list ap)
{
	int n;

	s++;
	if (*s == 'd' || *s == 'i')
		n = putint(va_arg(ap, int));
	else if (*s == 's')
	{
		n = _printf(va_arg(ap, char *));
	}
	else if (*s == 'c')
	{
		n = va_arg(ap, int);
		putchar(n);
		n = 1;
	}
	else if (*s == '%')
	{
		putchar('%');
		n = 1;
	}
	else if (*s == 'u')
	{
		n = uns(va_arg(ap, unsigned int));
	}
	s++;
	return (n);
}
/**
 * uns - prints unsigned int
 * @n: unsigned int
 * Return: int
 */
int uns(unsigned int n)
{
	int c;
	int i;
	int d;
	int arr[15];

	c = 0;
	i = 0;

	if (n == 0)
	{
		putchar('0');
		return (1);
	}
	while (n != 0)
	{
		arr[i] = n % 10;
		n /= 10;
		i++;
	}
	for (d = i - 1; d >= 0; d--)
	{
		putchar('0' + arr[d]);
		c++;
	}
	return (c);
}
/**
 * putint - printf integers
 * @n: int to print
 * Return: integer
 */
int putint(int n)
{
	int c;
	int i;
	int d;
	int arr[10];

	c = 0;
	i = 0;

	if (n == 0)
	{
		c++;
		putchar('0');
		return (1);
	}
	else if (n < 0)
	{
		putchar('-');
		n *= -1;
		c += 1;
	}
	while (n != 0)
	{
		arr[i] = n % 10;
		n /= 10;
		i++;
	}
	for (d = i - 1; d >= 0; d--)
	{
		putchar('0' + arr[d]);
		c++;
	}
	return (c);
}
/**
 * back - handles backslashes
 * @s: format string
 * Return: void
 */
void back(const char *s)
{
	s++;
	if (*s == 't')
		putchar('\t');
	else if (*s == 'n')
		putchar('\n');
	else if (*s == 'b')
		putchar('\b');
	else if (*s == '\\')
		putchar('\\');
}
