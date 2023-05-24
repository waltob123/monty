#include "monty.h"

/**
 * main - interpreter for Monty ByteCodes files.
 * @argc: argument count
 * @argv: argument values
 * Return: 0 or 1
 */

int main(int argc, char **argv)
{
	info.type = LIFO;
	if (argc != 2)
		handle_error(2);
	else
	{
	treat_monty(argv[1]);
	}
	return (EXIT_SUCCESS);
}
