#include "monty.h"

/**
 * pstr_monty - prints the string starting at the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: the line number
 * Return: void
 */

void pstr_monty(stack_t **stack, unsigned int line_number)
{
	int counter;
	stack_t *node;
	(void)line_number;

	node = *stack;
	if (*stack == NULL)
	{
		putchar('\n');
	}
	else
	{
		for (counter = 0; node; counter++)
		{
			if (node->n >= 65 && node->n <= 90)
				putchar(node->n);
			else if (node->n >= 97 && node->n <= 122)
				putchar(node->n);
			else if (node->n == 0)
				node = node->next;
			else
				break;
		node = node->next;
		}
		putchar('\n');
	}
}
