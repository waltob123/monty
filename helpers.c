#include "monty.h"

/**
 **_realloc -  reallocates a memory block using malloc and free
 *@ptr: pointer
 *@old_size: previous size of the pointer
 *@new_size: new size of the pointer
 *Return: void pointer rellocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);

}

/**
 * _memcpy - copy byte from source to destination
 * @dest: destination pointer
 * @src: source pointer
 * @n: size (how much you will copy)
 *Return: void pointer
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * fill_an_array - fill an array by constant byte
 * @a:void pointer
 * @el: int
 * @len:length int
 * Return: void pointer
 */

void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int counter = 0;

	while (counter < len)
	{
		*p = el;
		p++;
		counter++;
	}
	return (a);
}

/**
 * _isdigit - checks for a digit from 0 to 9
 * @str: the integer to be checked
 * Return: 1 or 0
 */

int _isdigit(char *str)
{
	int counter = 0;

	if (str == NULL)
		return (1);
	while (str[counter])
	{
		if (isdigit(*str) == 0)
			return (1);
		counter++;
	}
	return (0);
}
