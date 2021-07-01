#include "slide_line.h"
/**
 * collapse - Prints out an array of integer, followed by a new line
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 * @direction: direction
 * Return: 0 or 1
 */
int collapse(int *line, size_t size, int direction)
{
	size_t i, j;

	if (direction == -1)
	{
		for (j = size; j > 0; j--)
			if (line[j] == 0)
				break;
		for (i = size; i > 0; i--)
		{
			if (line[i] != 0 && line[j] == 0)
			{
				line[j] = line[i];
				line[i] = 0;
				for (j = size; j > 0; j--)
					if (line[j] == 0)
						break;
			}
		}
		return (1);
	}
	if (direction == 1)
	{
		for (j = 0; j < size; j++)
			if (line[j] == 0)
				break;
		for (i = 0; i < size; i++)
		{
			if (line[i] != 0 && line[j] == 0)
			{
				line[j] = line[i];
				line[i] = 0;
				for (j = 0; j < size; j++)
					if (line[j] == 0)
						break;
			}
		}
		return (1);
	}

	return (0);
}
/**
 * slide_line - Prints out an array of integer, followed by a new line
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 * @direction: direction
 * Return: 0 or 1
 */
int slide_line(int *line, size_t size, int direction)
{
	int tmp;
	size_t i, j;

	tmp = 0;
	for (i = 0; i < size; i++)
	{
		if (tmp == line[i] && tmp != 0)
		{
			line[i] += line[i];
			line[j] = 0;
			tmp = 0;
		}
		else
			if ((tmp == 0 && line[i] != 0) ||
			(tmp != line[i] && tmp != 0 && line[i] != 0))
			{
				tmp = line[i];
				j = i;
			}
	}
	return (collapse(line, size, direction));
}
