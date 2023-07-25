#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "main.h"

/* Helper function to print a character */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	putchar(c);
	return (1);
}

/* Helper function to print a string */
int print_string(va_list args)
{
	const char *str = va_arg(args, const char *);
	int count = 0;
	while (*str != '\0')
	{
		putchar(*str);
		str++;
		count++;
	}
	return (count);
}

/* Helper function to print an integer */
int print_integer(va_list args)
{
	char buffer[100];
	int num = va_arg(args, int);
	int count = snprintf(buffer, sizeof(buffer), "%d", num);
	fputs(buffer, stdout);
	return (count);
}

/**
 * _printf - Custom implementation of printf function
 * @format: Format string containing conversion specifiers
 *
 * Return: the number of characters printed (excluding the null byte
 * used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int count = 0;
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
				count += print_char(args);
				break;
			case 's':
				count += print_string(args);
				break;
			case 'd':
			case 'i':
				count += print_integer(args);
				break;
			case '%':
				putchar('%');
				count++;
				break;
			default:
				putchar('%');
				putchar(*format);
				count += 2;
				break;
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

