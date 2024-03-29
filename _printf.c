#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <string.h>
#include <stdio.h>
/**
 * _printf - prints out things on the standard out put
 * @format: formatted specifier
 * Return: Number of elements printed
 */


int _printf(const char *format, ...)
{
	va_list args;
	int character_count = 0;

	va_start(args, format);

	if (format == NULL)
	{
		va_end(args);
		return (character_count);
	}

	while (*format)
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

				write(1, &character, 1);
				character_count++;
			}
			if (*format == 's')
			{
				const char *string = va_arg(args, const char*);

				write(1, string, strlen(string));
				character_count += strlen(string);
			}
			if (*format == 'i' || *format == 'd')
			{
				 int number = va_arg(args, int);
				 char buffer[20];
				 int size = sprintf(buffer, "%d", number);
				 write(1, buffer, size);
				 character_count += size;
			}
			
		}

		format++;
	}

	va_end(args);
	return (character_count);
}
