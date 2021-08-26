#include "sort.h"
/**
 * sift_down - Entry point
 * @array: array
 * @size: size
 * @n: n
 * @i: i
 * Return: Always 0
 */
void sift_down(int *array, size_t size, size_t n, size_t i)
{
	size_t max, left, right, tmp;

	do {
		max = i;
		left = 2 * i + 1;
		right = 2 * i + 2;
		if (left < n && array[left] > array[max])
			max = left;
		if (right < n && array[right] > array[max])
			max = right;
		if (max != i)
		{
			tmp = array[i];
			array[i] = array[max];
			array[max] = tmp;
			print_array(array, size);
			i = max, max = 0;
		}
	} while (max != i);
}
/**
 * heap_sort - Entry point
 * @array: array
 * @size: size
 * Return: Always 0
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i;
	size_t tmp;

	if (!array || !size)
		return;
	for (i = size / 2 - 1; i > -1; --i)
		sift_down(array, size, size, i);
	for (i = size - 1; i > 0; --i)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		sift_down(array, size, i, 0);
	}
}
