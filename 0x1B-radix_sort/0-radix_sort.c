#include "sort.h"

/**
 * maximum - find the maximum
 * @array: array to be sorted
 * @size: size of the array
 * Return: the maximum value in the array
 */
int maximum(int *array, size_t size)
{
	int max = 0;
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * radix_count - counts the number of digits in maximum
 * @array: array to be sorted
 * @size: size of the array
 * @digit: Integer by which the array is divided to get the digit
 * Return: Void
 */
void radix_count(int *array, int size, int digit)
{
	int *count = malloc(sizeof(int) * (maximum(array, size) + 1));
	int *output = malloc(sizeof(int) * size);
	int i;

	if (count == NULL || output == NULL)
	{
		free(count);
		free(output);
	}
	for (i = 0; i <= maximum(array, size); i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i] / digit % 10]++;
	for (i = 1; i <= maximum(array, size); i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
		output[count[array[i] / digit % 10]-- - 1] = array[i];
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}

/**
 * radix_sort -  radix sort
 * @array: array to be sorted
 * @size: size of the array
 * Return: Void
 */
void radix_sort(int *array, size_t size)
{
	int i;

	for (i = 1; i < 100; i *= 10)
	{
		radix_count(array, size, i);
		print_array(array, size);
	}
}
