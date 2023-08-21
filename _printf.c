#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - prints out things on the standard out put
 * @format: formatted specifier
 * Return: Number of elements printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int character_count;

	if (format == NULL)
	{
		Return(-1);
	}

	while (*format && *format != '/0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			character_count++;
		}
		else
		{
			format++;

			if (*format == 'c')
			{
				char character = va_arg(args, int);

				write(1, character, 1);
				character_count++;
			}
			if (*format == 's')
			{
				const char *string = va_arg(args, const char*);

				write(1, string, _strlen(string));
				charater_count += _strlen(string);
			}
		}

	}
	return (character_count);
}
