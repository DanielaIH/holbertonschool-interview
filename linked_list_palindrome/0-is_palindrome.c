#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the list
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow, *fast, *prev, *second, *tmp;

    slow = *head;
    fast = *head;
    prev = NULL;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    if (fast != NULL)
        slow = slow->next;

    second = slow;
    prev->next = NULL;
    tmp = second;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        second->next = prev;
        prev = second;
        second = tmp;
    }

    tmp = prev;
    second = *head;

    while (tmp != NULL)
    {
        if (second->n != tmp->n)
            return (0);
        second = second->next;
        tmp = tmp->next;
    }

    return (1);
}
