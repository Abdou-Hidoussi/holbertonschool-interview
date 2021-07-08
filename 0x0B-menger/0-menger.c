#include "menger.h"
/**
 * menger - Entry point
 * @level: levels of the spunge
 */
void menger(int level)
{
	int i, j, size;

	if (level < 0)
		return;
	size = pow(3, level);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			printf("%c", hash_space(i, j));
		printf("\n");
	}
}
/**
 * hash_space - Entry point
 * @i: colum counter
 * @j: row counter vector
 * Return: space or #
 */
char hash_space(int i, int j)
{
	while (i && j)
	{
		if (i % 3 == 1 && j % 3 == 1)
			return (' ');
		i /= 3;
		j /= 3;
	}
	return ('#');
}
