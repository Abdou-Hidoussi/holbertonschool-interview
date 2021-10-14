#include "sort.h"
/**
 * merging - merge fragment
 * @array: original array
 * @coppy: copy of array
 * @low: index of start
 * @mid: index of mid
 * @high: index of end
 */
void merging(int *array, int *coppy, size_t low, size_t mid, size_t high)
{
	size_t i, l, r;

	printf("Merging...\n[left]: ");
	print_array(coppy + low, mid - low);
	printf("[right]: ");
	print_array(coppy + mid, high - mid);
	for (i = l = low, r = mid; i < high; ++i)
	{
		if (l < mid && (r >= high || coppy[l] <= coppy[r]))
			array[i] = coppy[l++];
		else
			array[i] = coppy[r++];
	}
	printf("[Done]: ");
	print_array(array + low, high - low);
}
/**
 * rec_merge - devide array
 * @array: original array
 * @coppy: copy of array
 * @low: index of start
 * @high: index of end
 */
void rec_merge(int *array, int *coppy, size_t low, size_t high)
{
	size_t mid;

	if (high - low <= 1)
		return;
	mid = (low + high) / 2;
	rec_merge(coppy, array, low, mid);
	rec_merge(coppy, array, mid, high);
	merging(array, coppy, low, mid, high);
}
/**
 * merge_sort - sort array
 * @array: original array
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *coppy;

	if (size == 1)
		return;
	coppy = malloc(size * sizeof(*array));
	if (!coppy)
		return;
	memcpy(coppy, array, size * sizeof(*coppy));
	rec_merge(array, coppy, 0, size);
	free(coppy);
}
