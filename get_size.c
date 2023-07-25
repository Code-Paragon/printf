#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
/**
 *  It checks for the presence of size specifiers "l" (for long)
 *  or "h" (for short) immediately after the current position in
 *  the format string. If a valid size specifier is found, the function
 *  returns the corresponding size value (S_LONG or S_SHORT), and
 *  if no valid size specifier is found, it returns 0. The index i is updated
 *  to ensure correct parsing of the format string in the _printf function
 */
