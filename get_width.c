#include "main.h"

/**
 * get_width - Calculates the width
 * @format: Formatted string to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: width.
 */

int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{

	}

	*i = curr_i - 1;

	return (width);
}
