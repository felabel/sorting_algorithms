#include "sort.h"

/**
*swap_elements_fk - switches positions of 2 elements in an array
*@array: array
*@x: element to switch
*@d: element to switch
*/
void swap_elements_fk(int *array, int x, int d)
{

	int tmp;

	tmp = array[x];
	array[x] = array[d];
	array[d] = tmp;
}
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, index = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (index = i; index >= gap &&
			 (array[index] < array[index - gap]); index -= gap)
				swap_elements_fk(array, index, index - gap);
		print_array(array, size);
		gap /= 3;
	}
}
