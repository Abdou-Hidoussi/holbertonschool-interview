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

	if (direction == -1)
	{
		moving_right(line, size);
		return (1);
	}
	if (direction == 1)
	{
		moving_left(line, size);
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
void moving_left(int *line, size_t size)
{
    int i = 0, j, previous = 0, current;

    for (j = 0; j < (int)size; j++)
    {
        current = line[j];
        if (!current)
            continue;
        if (!previous)
            previous = current;
        else if (previous == current)
        {
            line[i++] = current << 1;
            previous = 0;
        } else
        {
            line[i++] = previous;
            previous = current;
        }
    }
    if (previous)
        line[i++] = previous;
    while (i < (int)size)
        line[i++] = 0;
}

/**
 * tothe_right - slides a line to the right
 * @line: input array
 * @size: size of array
 */
void moving_right(int *line, size_t size)
{
    int previous = 0, i = size - 1, j, current;

    for (j = size - 1; j >= 0; j--)
    {
        current = line[j];
        if (!current)
            continue;
        if (!previous)
            previous = current;
        else if (previous == current)
        {
            line[i--] = current << 1;
            previous = 0;
        } else
        {
            line[i--] = previous;
            previous = current;
        }
    }
    if (previous)
        line[i--] = previous;
    while (i >= 0)
        line[i--] = 0;
}
