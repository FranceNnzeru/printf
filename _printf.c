/**
 * printf - Custom implementation of printf function
 * @format: format string containing conversion specifiers
 *
 * Description: This function produces output according
 * to a format string
 * that may contain conversion specifiers for
 * characters, strings, and intergers.
 *
 * Return: the number of character printed
 * (excluding the null byte used to end output to strings).
 */

#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/*
 * Function to handle the conversion specifiers
 */
void handle_specifier(char specifier, va_list args, int *count)
{
	char c;
	const char *str;

	switch (specifier)
	{
		case 'c':
		c = va_arg(args, int);
		putchar(c);
		(*count)++;

		break;
		case 's':
		str = va_arg(args, const char*);

		while (*str != '\0')
		{
			putchar (*str);
			str++;
			(*count) += '2'
				break;
		}
	}

	int _printf(const char *format, ...)
	{
		va_list arg;
		va_start(args,format);
		int count = 0;

		while (*format != '\0')
		{
			if (*format == '%')
			{
				format++;
				handle_specifier(*format, arg, &count);
			}
			else
			{
				putchar (*format);
				count++;
			}
			va_end(args);
			return count;
		}
