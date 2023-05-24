#include "monty.h"

/**
 * add_error - prints error when add command and stack is too short
 */

void add_error(void)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", info.l_number);
	free_info();
}

/**
 * sub_error - prints error when sub command and stack is too short
 */

void sub_error(void)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", info.l_number);
	free_info();
}

/**
 * monty_usage - prints error for interpteur usage
 */

void monty_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
}

/**
 * div_error - prints error when stack is too short command div
 */

void div_error(void)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", info.l_number);
	free_info();
}
