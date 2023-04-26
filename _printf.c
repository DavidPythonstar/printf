#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - takes in variable number of aguments
 *format: pointer to the first address of the variable arguments
 * @... : infinite variable list
 * Return: counter
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int i = 0;
	int counter = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'd':
					{
						int x = va_arg(args, int);

						putchar(x);
						break;
					}
				case 'f':
					{
						 double x = va_arg(args, double);

						 putchar(x);
						 break;
					}
				case 'c':
					{
						int x = va_arg(args, int);

						putchar(x);
						break;
					}
				case 'i':
					{
						int x = va_arg(args, int);

						putchar(x);
						break;
					}
				case 's':
					{
						char *x = va_arg(args, char*);
						int i = 0;

						while (x[i] != '\0')
						{
							putchar(x[i]);
							i++;
						}
						break;
					}
				case 'x':
				case 'X':
					{
						int x = va_arg(args, int);

						putchar(x);
						break;
					}
					/**
				case 'p':
					{
						void *x = va_arg(args, void*);

						putchar(x);
						break;
					}
					*/
				case 'o':
					{
						int x = va_arg(args, int);

						putchar(x);
						break;
					}
				case 'u':
					{
						int x = va_arg(args, int);

						putchar(x);
						break;
					}
				case '%':
					{
						putchar('%');
						break;
					}
				default:
					putchar(format[i]);
					break;
			}
		} else
		{
			putchar(format[i]);
		}
		i++;
		counter++;
	}
	va_end(args);
	return (counter);
}
