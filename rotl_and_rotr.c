#include "monty.h"

/**
 * rotl_monty -  rotates the stack to the top
 * @stack: pointer to the head of the stack
 * @line_number: the line number
 * Return: void
 */

void rotl_monty(stack_t **stack, unsigned int line_number)
{
	int tmp;
	stack_t *copy;

	(void)line_number;

	if (stack && *stack)
	{
		tmp = (*stack)->n;

		for (copy = *stack; copy->next; copy = copy->next)
			copy->n = copy->next->n;
		copy->n = tmp;
	}
}

/**
 * rotr_monty - rotates the stack to the bottom.
 * @stack: pointer to the head
 * @line_number: the line number
 * Return: void
 */

void rotr_monty(stack_t **stack, unsigned int line_number)
{
	int next, current;
	stack_t *copy;

	(void)line_number;

	if (stack && *stack)
	{
		copy = *stack;
		next = copy->n;

		while (copy->next)
		{
			current = next;
			next = copy->next->n;
			copy->next->n = current;
			copy = copy->next;
		}
		(*stack)->n = next;
	}
}
