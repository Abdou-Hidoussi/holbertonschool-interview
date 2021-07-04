#include "slide_line.h"
/**
 * left_shift - slides a line to the left
 * @line: input array
 * @size: size of array
 */
void left_shift(int *line, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0 && line[i + 1] != 0)
		{
			line[i] = line[i + 1];
			line[i + 1] = 0;
			for (i = 0; i < size; i++)
				if (line[i] == 0)
					break;
			i--;
		}
	}
}
/**
 * right_shift - slides a line to the right
 * @line: input array
 * @size: size of array
 */
void right_shift(int *line, size_t size)
{
	size_t i;

	for (i = size - 1; i != 0; i--)
	{
		if (line[i] == 0 && line[i - 1] != 0)
		{
			line[i] = line[i - 1];
			line[i - 1] = 0;
			for (i = size - 1; i != 0; i--)
				if (line[i] == 0)
					break;
			i++;
		}
	}
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
	size_t i;

	switch (direction)
	{
		case SLIDE_RIGHT:
			right_shift(line, size);
			for (i = size - 1; i != 0; i--)
				if (line[i] == line[i - 1])
				{
					line[i] += line[i - 1];
					line[i - 1] = 0;
				}
			right_shift(line, size);
			return (1);
		case SLIDE_LEFT:
			left_shift(line, size);
			for (i = 0; i < size; i++)
				if (line[i] == line[i + 1])
				{
					line[i] += line[i + 1];
					line[i + 1] = 0;
				}

			left_shift(line, size);
			return (1);
	}
	return (0);
}
