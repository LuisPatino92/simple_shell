#include "shell.h"

/**
 * int_to_string - processes a number as a string
 * @number: The number to be processed
 *
 * Return: The number as a string
 */

char *int_to_string(int number)
{
	char *num_str;
	int len = 0, digits = 1, j;
	long i;

	for (i = 10; absolute(number) / i > 0; i = i * 10)
	{
		digits++;
	}

	if (number < 0)
		len = digits + 1;
	else
		len = digits;

	num_str = malloc(sizeof(char) * (len + 1));
	if (num_str == NULL)
		exit(0);

	i = 0;
	if (number < 0)
	{
		*(num_str) = '-';
		i++;
	}
	for (j = 1; i < len; i++, j++)
	{

		*(num_str + i) = ((absolute(number) / (pot(10, (digits - j)))) % 10) + 48;

	}
	*(num_str + i) = '\0';

	return (num_str);
}

/**
 * absolute - Absolute value
 *
 * @n: The number whose absolute value is needed
 *
 * Return: The absolute value
 */

long absolute(long n)
{
	if (n < 0)
		return (-1 * n);
	else
		return (n);
}

/**
 * pot - potetiation of x ** y
 *
 * @x: The base
 * @y: The exponenr
 *
 * Return: The result of x ** y
 */

int pot(int x, int y)
{
	int i, resultado = 1;

	for (i = 0; i < y; i++)
	{
		resultado = resultado * x;
	}
	return (resultado);
}

/**
 * _calloc - allocate memory wich has been initialized to zero
 * @nelem: amount of elements
 * @nsize: size depend data type
 * Return: pointer
 */

char *_calloc(int nelem, int nsize)
{
	char *ptr = NULL;
	int i;

	if (nelem == 0 || nsize == 0)
		return (NULL);

	ptr = malloc(nelem * nsize);

	if (!ptr)
		return (NULL);
	for (i = 0; i < (nelem * nsize); i++)
		ptr[i] = 0;

return (ptr);
}
