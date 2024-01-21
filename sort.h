#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

typedef struct listint_s {
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
listint_t *swap_node(listint_t *node, listint_t **list);

#endif
