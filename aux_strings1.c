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
 * @nmemb: amount of elements
 * @size: size depend data type
 * Return: pointer
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *P = NULL;

	if (nmemb == 0 || size == 0)
		return (NULL);

	P = malloc(nmemb * size * sizeof(char));

	if (P == NULL)
	{
		free(P);
		return (NULL);
	}
	for (i = 0; i < nmemb * size; i++)
		*(P + i) = 0;

	return (P);

}

/**
 * _strcmp - comparate
 * @s1: hello
 * @s2: World!
 * Return: Diference betwen letters
 */

int _strcmp(char *s1, char *s2)
{
	int i, n = 0;

	for (i = 0; s1[i] != 0; i++)
	{
		if (s1[i] != s2[i])
		{
			n = s1[i] - s2[i];
			return (n);
		}
	}
	return (n);
}
