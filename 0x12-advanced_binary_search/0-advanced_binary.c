#include "search_algos.h"
/**
 * advanced_binary_counter - searches for a value in a sorted array of integers
 * @array: pointer to array to search
 * @r: right counter
 * @l: left counter
 * @value: value to search for
 *
 * Return: index or -1
 */
int advanced_binary_counter(int *array, int value, int l, int r)
{
	int i;

	if (l == r)
	{
		if (array[l] == value)
		{
			return (l);
		}
		else
		{
			printf("Searching in array:");
			for (i = l; i <= r; i++)
				i != r ? printf(" %i,", array[i]) : printf(" %i\n", array[i]);
			return (-1);
		}
	}
	printf("Searching in array:");
	for (i = l; i <= r; i++)
		i != r ? printf(" %i,", array[i]) : printf(" %i\n", array[i]);

	if (array[(l + r) / 2] < value)
		return (advanced_binary_counter(array, value, (((l + r) / 2) + 1), r));
	else
		return (advanced_binary_counter(array, value, l, ((l + r) / 2)));
}
/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to array to search
 * @size: size of array
 * @value: value to search for
 *
 * Return: index or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array && size > 0)
		return (advanced_binary_counter(array, value, 0, size - 1));
	else
		return (-1);
}
