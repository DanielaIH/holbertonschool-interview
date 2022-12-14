#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to the head's list.
 * @number: the number to be inserted.
 * Return: the address of the new node, or NULL if it failed.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	if (head == NULL)
		return (NULL);

	current = *head;

	while (current && current->next && current->next->n <= number)
		current = current->next;

	if (!current || !current->next)
		return (add_nodeint_end(head, number));

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;

	if (current == *head)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	new->next = current->next;
	current->next = new;
	return (new);
}
