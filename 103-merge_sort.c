#include "sort.h"
/**
 * merge_sort - sorts an array with the merge sort method
 * @array: array to be sorted
 * @size: size of the array
 */

void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	merge_sort_rcsv(array, 0, size - 1);
}

/**
 * merge_sort_rcsv - recursively sorts the subarrays
 * @array: array to be sorted
 * @lft: index of the left subarray
 * @rgt: index of the right subarray
 */

void merge_sort_rcsv(int *array, size_t lft, size_t rgt)
{
	if (lft < rgt)
	{
		size_t mid = lft + (rgt - lft) / 2;

		merge_sort_rcsv(array, lft, mid);
		merge_sort_rcsv(array, mid + 1, rgt);
		merge_sorted_arrays(array, lft, mid, rgt);
	}
}

/**
 * merge_sorted_arrays - merges two sorted arrays
 * @array: array to be sorted
 * @lft: index of the left subarray
 * @mid: index at the middle of the array
 * @rgt: index of the right subarray
 */

void merge_sorted_arrays(int *array, size_t lft, size_t mid, size_t rgt)
{
	size_t lft_lnth = mid - lft + 1;
	size_t rgt_lnth = rgt - mid;
	size_t tmp_lft[lft_lnth], tmp_rgt[rgt_lnth];

	int i, j, k;

	for (i = 0; i < lft_lnth; i++)
		tmp_lft[i] = array[lft + i];
	for (j = 0; j < rgt_lnth; j++)
		tmp_rgt[j] = array[mid + 1 + j];
	for (i = 0, j = 0, k = lft; k <= rgt; k++)
	{
		if ((i < lft_lnth) && (j >= rgt_lnth || tmp_lft[i] <= tmp_rgt[j]))
		{
			array[k] = tmp_lft[i];
			i++;
		}
		else
		{
			array[k] = tmp_rgt[j];
			j++;
		}
	}
}
