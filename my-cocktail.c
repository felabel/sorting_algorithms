#include "sort.h"
#include <stdio.h>

/**
 *cocktail_sort_list - sorts an array with the cokatail method
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swapped = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	node = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				swapped = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				swapped = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}

/**
 * swap_node - swaps the nodes of a doubly linked list
 * @node: node to be swapped
 * @list: list to be sorted
 * Return: node
 */

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prv_node = node->prev, *cur_node = node;


	prv_node->next = cur_node->next;
	if (cur_node->next)
		cur_node->next->prev = prv_node;
	cur_node->next = prv_node;
	cur_node->prev = prv_node->prev;
	prv_node->prev = cur_node;
	if (cur_node->prev)
		cur_node->prev->next = cur_node;
	else
		*list = cur_node;
	return (cur_node);
}
