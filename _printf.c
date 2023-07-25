#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string containing the conversion specifiers
 *
 * Return: Numbers of characters printed (excluding the null)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && (++format))
		{
			switch (*format++)
			{
				case 'c':
					puthcar(va_arg(args, int));
					count++;
					break;
				case 's':
					for (char *str = va_arg(args, char *); *str; str++)
					{
						putchar(*str);
						count++;
					}
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(*(format - 1));
						count += 2;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
