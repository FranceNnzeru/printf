#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string containing the conversion specifiers
 *
 * Return: Number of characters printed (excluding the null)
 */
int _printf(const char *format,char c, char s...)
{
	int count = 0;
	char c, *str;
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);

					putchar(c), count++;
					break;

				case 's':
					str = va_arg(args, char*);

					while (*str)
						putchar(*str), str++, count++;
					break;

				case '%':
					putchar ('%'), count++;
					break;
				default:
					putchar ('%'), putchar (*format), count += 2;

						break;
			}
		}
		else
			putchar(*format), count++;
		format++;
	}
	va_end(args);
	return (count);
}
