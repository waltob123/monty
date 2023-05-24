#include "monty.h"

/**
 * dlistint_len - return list length
 * @stack: head of stack or queue
 * Return: list length
 */

int dlistint_len(stack_t *stack)
{
	int len = 0;
	int counter = 0;

	for (counter = 0; stack; counter++)
	{
		len += 1;
		stack = stack->next;
	}
	return (len);
}

/**
 * delete_dnodeint_at_index - delete node at give index
 * @head: list
 * @index: given index
 * Return: -1 or 0
 */

int delete_dnodeint_at_index(stack_t **head, int index)
{
	stack_t *start;
	 int counter;
	 int len = dlistint_len(*head);

	start = *head;
	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		start = start->next;
		free(*head);
		*head = start;
		if (start != NULL)
			start->prev = NULL;
		return (1);
	}
	for (counter = 0; counter <= index - 1; counter++)
	{
		start = start->next;
		if (!start)
			return (-1);
	}
	if (len - 1 == index)
	{
		start->prev->next = NULL;
		free(start);
		return (1);
	}
	start->prev->next = start->next;
	start->next->prev = start->prev;
	free(start);
	return (1);
}
