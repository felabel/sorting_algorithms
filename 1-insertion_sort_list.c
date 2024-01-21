#include "sort.h"
/**
  * insertion_sort_list - sorts a doubly linked list of integers in   
  *ascending order
  * @list: list to be sorted
  */

void insertion_sort_list(listint_t **list)
{
  listint_t *node;

  if (list == NULL || (*list)->next == NULL)
    return;
  node = (*list)->next;
  while (node)
  {
    while ((node->prev) && (node->prev->n > node->n))
    {
      node = swap_node(node, list);
      print_list(*list);
    }
    node = node->next;
  }
}

/**
* swap_node - swaps the nodes of a doubly linked list
* node: node to be swapped
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