#include "sort.h"
/**
 * swap_elements_fk - swaps two elements
 * @x: integer to be swapped
 * @d: integer to be swapped
 */

void swap_elements_fk(int *x, int *d)
{
	int t = *x;
	*x = *d;
	*d = t;
}

/**
 * partition - divides the array into left and right around the pivot
 * @array: array to be sorted
 * @min_index_fk: lowest index in the subarray
 * @max_index_fk: highest index in the subarray
 * @size: size of the array
 * Return: integer value
 */

int partition(int *array, int min_index_fk, int max_index_fk, size_t size)
{
	int pivot = array[max_index_fk], i = (min_index_fk - 1), j;

	for (j = min_index_fk; j <= max_index_fk - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_elements_fk(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap_elements_fk(&array[i + 1], &array[max_index_fk]);
	print_array(array, size);
	return (i + 1);
}

/**
 * rcsv_sort - repeated partions the array
 * @array: array to be sorted
 * @min_index_fk: lowest index in the subarray
 * @max_index_fk: highest index in the subarray
 * @size: size of the array
 */

void rcsv_sort(int *array, int min_index_fk, int max_index_fk, size_t size)
{
	if (min_index_fk < max_index_fk)
	{
		int pvt_idx = partition(array, min_index_fk, max_index_fk, size);

		rcsv_sort(array, min_index_fk, pvt_idx - 1, size);
		rcsv_sort(array, pvt_idx + 1, max_index_fk, size);
	}
}

/**
 * quick_sort - returns the sorted array
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	rcsv_sort(array, 0, size - 1, size);
}
