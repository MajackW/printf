#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - custom printf function
 * @format: what to print
 * Return: int number of prints
 */
int _printf(const char *format, ...)
{
	int n;
	va_list ap;

	va_start(ap, format);
	n = 0;
	while (*format != '\0')
	{
		if (*format == '\\')
		{
			format++;
			back(format);
			n += 1;
			format++;
		}
		if (*format == '%')
		{
			format++;
			n += mod(format, ap);
			format++;
		}
		putchar(*format);
		n += 1;
		format++;
	}
	va_end(ap);
	return (n);
}
/**
 * mod - handles modulos
 * @s: string format
 * @ap: variadic arguments
 * Return: int
 */
int mod(const char *s, va_list ap)
{
	int n;
	char *p;

	n = 0;

	if (*s == 's')
	{
		p = va_arg(ap, char *);
		n = _printf(p);
	}
	if (*s == 'd' || *s == 'i')
	{
		n = putint(va_arg(ap, int));
	}
	if (*s == 'c')
	{
		p = va_arg(ap, char *);
		n = _printf(p);
	}
	s++;
	return (n);
}
/**
 * back - handles backlashes
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
	else if (*s == '\\')
		putchar('\\');
	else
		exit(98);
}