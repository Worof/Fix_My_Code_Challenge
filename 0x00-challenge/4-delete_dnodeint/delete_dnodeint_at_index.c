#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *saved_head;
    dlistint_t *tmp;
    unsigned int p;

    if (*head == NULL)
    {
        return (-1);
    }
    saved_head = *head;
    p = 0;
    while (p < index && *head != NULL)
    {
        *head = (*head)->next;
        p++;
    }
    if (p != index || *head == NULL) // Also check if *head is NULL after the loop
    {
        *head = saved_head;
        return (-1);
    }
    if (0 == index)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
        if (tmp != NULL)
        {
            tmp->prev = NULL;
        }
    }
    else
    {
        tmp = (*head); // Save the current node to be deleted
        tmp->prev->next = tmp->next; // Link the previous node to the next node
        if (tmp->next)
            tmp->next->prev = tmp->prev; // Link the next node back to the previous node
        free(tmp); // Now, safely delete the node
        *head = saved_head; // Restore the head pointer
    }
    return (1);
}
