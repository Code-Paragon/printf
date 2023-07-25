#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf our string
 * @format: string to be printed
 *
 * Return: Printed characters
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	/* BUFF_SIZE is 1024 */
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		/* For char that are not specifiers */
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
			/* For specifiers */
		{
			/* First print all chars before the specifier */
			print_buffer(buffer, &buff_ind);
/* extract any flags specified in format code,modify position to skip flags */
			flags = get_flags(format, &i);
/* extract field width from format code,access next arg in list,if needed */
			width = get_width(format, &i, list);
/* to extract the precision from the format code and handles precision. */
			precision = get_precision(format, &i, list);
			/* to extract any length modifiers */
			size = get_size(format, &i);
			++i;
/* passes the info extracted, along with buffer, to print formatted content */
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	
/* after processing format string we print any remaining char in buffer */
	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists.
 * @buffer: Array of characters
 *
 * @buff_ind: Index at which to add next character, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
