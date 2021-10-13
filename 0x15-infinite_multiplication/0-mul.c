#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * pproduct - print product array
 * @product: array to print
 * @len: len of array
 */
void pproduct(int *product, size_t len)
{
	size_t i;

	if (product == NULL || len == 0)
	{
		printf("0\n");
		return;
	}
	for (i = *product ? 0 : 1; i < len; ++i)
		printf("%i", product[i]);
	putchar('\n');
}

/**
 * mul - multiply two numbers represented as strings
 * @product: array to store product
 * @n1: first string
 * @n2: second string
 * @len1: length of first string
 * @len2: length of second string
 */
void mul(int *product, char *n1, char *n2, size_t len1, size_t len2)
{
	int i, j, carry;

	for (i = len1 - 1; i > -1; --i)
		for (j = len2 - 1; j > -1; --j)
		{
			carry = (n1[i] - '0') * (n2[j] - '0') + product[i + j + 1];
			product[i + j + 1] = carry % 10;
			product[i + j] += carry / 10;
		}
}

/**
 * check_error - check for usage errors
 * @argc: number of command-line arguments
 * @argv: argv from main without executable name
 *
 * Will exit with status of 98 on usage error
 */
void check_error(int argc, char *argv[])
{
	int i, j;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = 0; argv[i] != NULL; ++i)
		for (j = 0; argv[i][j]; ++j)
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				exit(98);
			}
}

/**
 * main - entry point for infinite multiplication
 * @argc: number of command-line arguments
 * @argv: pointer to an array of character strings containing the arguments
 *
 * Return: 0 on success or 1 on error
 */
int main(int argc, char *argv[])
{
	int *product;
	size_t len1, len2;

	check_error(argc, argv + 1);
	if (*argv[1] == '0' || *argv[2] == '0')
	{
		pproduct(NULL, 0);
		return (0);
	}
	len1 = strlen(argv[1]), len2 = strlen(argv[2]);
	product = calloc(len1 + len2, sizeof(*product));
	if (product == NULL)
		return (1);
	mul(product, argv[1], argv[2], len1, len2);
	pproduct(product, len1 + len2);
	free(product);
	return (0);
}
