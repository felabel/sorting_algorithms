#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

/**
 * struct listint_s - create a doubly linked node
 * @n: data item
 * @prev: pointer to previous node
 * @next: pointer to next node
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
listint_t *swap_node(listint_t *node, listint_t **list);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);

#endif
