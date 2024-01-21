#include "sort.h"
/**
*swap_elements_fkwap - swap 2 elements
*@array: array
*@x: element to swap
*@d: element to swap
*/
void swap_elements_fkwap(int *array, ssize_t x, ssize_t d)
{
	int tmp;

	tmp = array[x];
	array[x] = array[d];
	array[d] = tmp;
}

/**
 *partition - lomuto partition sorting scheme implementation
 *@array: array
 *@min_index_fk: last element in the array 
 *@max_index_fk: first element in the array 
 *@size: size array
 *Return: return the position of the last element sorted
 */
int partition(int *array, ssize_t min_index_fk, ssize_t max_index_fk, size_t size)
{
	int pivot = array[max_index_fk];
	ssize_t current = min_index_fk, j;

	for (j = min_index_fk; j < max_index_fk; j++)
	{
		if (array[j] < pivot)
		{
			if (array[current] != array[j])
			{
				swap_elements_fkwap(array, current, j);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[max_index_fk])
	{
		swap_elements_fkwap(array, current, max_index_fk);
		print_array(array, size);
	}
	return (current);
}
/**
 *rcsv_sort - divides the array into left and right around the pivot
 *@array: array
 *@min_index_fk: lowest array element
 *@max_index_fk: highest array element
 *@size: array size
 */
void rcsv_sort(int *array, ssize_t min_index_fk, ssize_t max_index_fk, int size)
{
	ssize_t position = 0;


	if (min_index_fk < max_index_fk)
	{
		position = partition(array, min_index_fk, max_index_fk, size);

		rcsv_sort(array, min_index_fk, position - 1, size);
		rcsv_sort(array, position + 1, max_index_fk, size);
	}
}
/**
 *quick_sort - returns the sorted array
 *@array: array to be sorted
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	rcsv_sort(array, 0, size - 1, size);
}
