#include "sort.h"
/**
 * selection_sort - it sorts an array of integers in asc order
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
    int swapCount, temp, current;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		temp = i;
		swapCount = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[temp] > array[j])
			{
				temp = j;
				swapCount += 1;
			}
		}
		current = array[i];
		array[i] = array[temp];
		array[temp] = current;
		if (swapCount > 0)
		{
			print_array(array, size);
		}
	}
}
