#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "main.h"
/**
 * _printf - Custom implementation of printf function
 * @format: Format string containing conversion specifiers
 * by Mabuela and Tanani 
 * (excluding the null byte used to end
 *  output to strings).
 */

int _printf(const char *format, ...)
{
	int count = 0;
        char buffer[100];
	char *str = buffer;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				char c = va_arg(args, int);
				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				const char *str = va_arg(args, const char *);
				while (*str != '\0')
				{
					putchar(*str);
					str++;
					count++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				snprintf(buffer, sizeof(buffer), "%d", num);
				while (*str != '\0')
				{
					putchar(*str);
					str++;
					count++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				putchar('%');
				putchar(*format);
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

