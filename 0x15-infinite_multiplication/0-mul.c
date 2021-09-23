#include <stdio.h>
#include <stdlib.h>
/**
*_strlen - 0
*@s: char
*Return:: i
*/
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

/**
 * mul - multiply two numbers
 * @result: array result
 * @n1: string
 * @n2: string
 * @len1: length of string
 * @len2: length of string
 */
void mul(int *result, char *n1, char *n2, size_t len1, size_t len2)
{
	int i, j, top;

	for (i = len1 - 1; i > -1; i--)
		for (j = len2 - 1; j > -1; j--)
		{
			top = (n1[i] - '0') * (n2[j] - '0') + result[i + j + 1];
			result[i + j + 1] = top % 10;
			result[i + j] += top / 10;
		}
}

/**
 * pre_calc - precalculations
 * @argc: argc
 * @argv: argv
 */
void pre_calc(int argc, char *argv[])
{
	int i, j;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 1; argv[i] != NULL; i++)
		for (j = 0; argv[i][j]; j++)
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				exit(98);
			}

	if (*argv[1] == '0' || *argv[2] == '0')
	{
		printf("0\n");
		return;
	}
}

/**
 * main - infinite multiplication
 * @argc: argc
 * @argv: argv
 *
 * Return: 0 on success or 1 on error
 */
int main(int argc, char *argv[])
{
	int *result;
	size_t len1, len2, i;

	pre_calc(argc, argv);

	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);

	result = malloc((len1 + len2) * sizeof(*result));
	if (result == NULL)
		return (1);

	mul(result, argv[1], argv[2], len1, len2);

	if (result == NULL || len1 + len2 == 0)
		printf("0\n");
	for (i = *result ? 0 : 1; i < len1 + len2; i++)
		printf("%i", result[i]);
	_putchar('\n');
	free(result);
	return (0);
}
