#include "sort.h"

void merge_subarr(int *subarr, int *temp_buff, size_t front, size_t mid,
		size_t back);
void merge_sort_rcsv(int *subarr, int *temp_buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @temp_buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarr(int *subarr, int *temp_buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		temp_buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		temp_buff[k++] = subarr[i];
	for (; j < back; j++)
		temp_buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = temp_buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_rcsv - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @temp_buff: A temp_buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_rcsv(int *subarr, int *temp_buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_rcsv(subarr, temp_buff, front, mid);
		merge_sort_rcsv(subarr, temp_buff, mid, back);
		merge_subarr(subarr, temp_buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *temp_buff;

	if (array == NULL || size < 2)
		return;

	temp_buff = malloc(sizeof(int) * size);
	if (temp_buff == NULL)
		return;

	merge_sort_rcsv(array, temp_buff, 0, size);

	free(temp_buff);
}

