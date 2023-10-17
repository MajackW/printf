#include <stdio.h>
#include "main.h"
/**
 * putint - puts integers
 * @n: int to print
 * Return: int number of characters
 */
int putint(int n)
{
	int c;
	int p;
	int i;
	int j;
	int arr[10];

	i = 0;
	c = 0;
	if (n < 0)
	{
		putchar('-');
		c += 1;
		n *= -1;
	}
	if (n == 0)
	{
		print(0);
		c += 1;
		return (c);
	}
	else
	{
		while (n > 0)
		{
			p = n % 10;
			arr[i] = p;
			i++;
			c += 1;
			n = n / 10;
		}
	}
	for (j = i - 1; j >= 0; j--)
	{
		print(arr[j]);
	}
	return (c);
}
/**
 * print - helper function to print ints
 * @d: int to print
 * Return: void
 */
void print(int d)
{
	putchar('0' + d);
}
