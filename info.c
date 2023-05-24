#include "monty.h"

info_t info;

/**
 * treat_monty - treat the monty file
 * @filename: filename from argument
 * Return: data of the monty file
 */

int treat_monty(char *filename)
{
	ssize_t n_r = 1;
	size_t len = 0;
	stack_t *stack = NULL;

	info.fn = filename;
	info.fp = fopen(info.fn, "r");
	if (info.fp == NULL)
		handle_error(3);
	while ((n_r = getline(&info.cmd, &len, info.fp)) > 0)
	{
		if (*info.cmd == '\n')
			continue;
		info.l_number++;
		free(info.arg);
		if (split() < 0)
			continue;
		if (info.arg == NULL)
			continue;
		excute_monty(&stack);
	}
	free_info();
	free_list(stack);
	return (0);
}

/**
 * split - split the line into command and arguments
 *Return: 0 or 1
 */

int split(void)
{
	char *token;
	size_t bufsize = 20, i = 0;

	info.arg = malloc(bufsize * sizeof(char *));
	if (info.arg == NULL)
		handle_error(1);
	token = strtok(info.cmd, DELIMITER);
	while (token)
	{
		info.arg[i++] = token;
		if (i >= bufsize)
		{
			info.arg = _realloc(info.arg, bufsize, bufsize * 2);
			if (info.arg == NULL)
			{
				handle_error(1);
			}
		}
		token = strtok(NULL, DELIMITER);
	}
	info.arg[i] = NULL;
	if (**info.arg == '#')
		return (-1);
	return (0);
}

#include "monty.h"

/**
 * excute_monty - verify monty command and excute it
 * @stack: stack or queue
 * Return: 0 or 1
 */

int excute_monty(stack_t **stack)
{
	instruction_t command[] = {
		{"push", push_monty},
		{"pall", pall_monty},
		{"pint", pint_monty},
		{"pop", pop_monty},
		{"swap", swap_monty},
		{"add", add_monty},
		{"nop", nop_monty},
		{"sub", sub_monty},
		{"div", div_monty},
		{"mul", mul_monty},
		{"mod", mod_monty},
		{"#", nop_monty},
		{"pchar", pchar_monty},
		{"pstr", pstr_monty},
		{"rotl", rotl_monty},
		{"rotr", rotr_monty},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	int counter = 0;

	while ((command + counter)->opcode)
	{
		if (strcmp((command + counter)->opcode, *info.arg) == 0)
		{
			(command + counter)->f(stack, info.l_number);
			return (0);
		}
		counter++;
	}
	handle_error(4);
	return (1);
}
