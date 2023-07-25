#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "main.h"

/**
 * print_char - Helper function to print a character
 * @args: va_list containing the arguments
 *
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	
	putchar(c);
	return (1);
}

/**
 * print_string - Helper function to print a string
 * @args: va_list containing the arguments
 *
 * Return: Number of characters printed
 */
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

/**
 * print_integer - Helper function to print an integer
 * @args: va_list containing the arguments
 * print_binary - helper function to print binary
 *
 * Return: Number of characters printed
 */
int print_integer(va_list args)
{
	char buffer[100];
	
	int num = va_arg(args, int);
	int count = snprintf(buffer, sizeof(buffer), "%d", num);
	fputs(buffer, stdout);
	return (count);
}

int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	
	int count = 0;
	char buffer[64];
	int index = 0;

	if (num == 0)
	{
		putchar('0');
		return (1);
	}
	while (num > 0)
	{
		buffer[index++] = (num & 1) + '0';
		num >>= 1;
	}
	while (--index >= 0)
	{
		putchar(buffer[index]);
		count++;
	}
	return count;
}

int print_unsigned(va_list args)
{
	char buffer[100];
	unsigned int num = va_arg(args, unsigned int);
	int count = snprintf(buffer, sizeof(buffer), "%u", num);
	fputs(buffer, stdout);
	return (count);
}

int print_octal(va_list args)
{
	char buffer[100];
	unsigned int num = va_arg(args, unsigned int);
	int count = snprintf(buffer, sizeof(buffer), "%o", num);
	fputs(buffer, stdout);
	return (count);
}

int print_hex(va_list args, int uppercase)
{
	char buffer[100];
	unsigned int num = va_arg(args, unsigned int);
	const char *format = (uppercase) ? "%X" : "%x";
	int count = snprintf(buffer, sizeof(buffer), format, num);
	fputs(buffer, stdout);
	return (count);
}

#define BUFFER_SIZE 1024

int print_unsigned(char *buffer, unsigned int num)
{
	int count = snprintf(buffer, BUFFER_SIZE, "%u", num);
	write(1, buffer, count);
	return count;
}

int print_octal(char *buffer, unsigned int num)
{
	int count = snprintf(buffer, BUFFER_SIZE, "%o", num);
	write(1, buffer, count);
	return (count);
}

int print_hex(char *buffer, unsigned int num uppercase)
{
	const char *format = (uppercase) ? "%X" : "%x";
	intcount = snprintf(buffer, BUFFER_SIZE, format, num);
	write(1, buffer,count);
	return count;
}

/**
 * print_conversion_specifier - Helper function for the switch statement inside _printf
 * @specifier: Conversion specifier
 * @args: va_list containing the arguments
 *
 * Return: Number of characters printed
 */
int print_conversion_specifier(char specifier, va_list args)
{
	switch (specifier)
	{
	case 'c':
		return (print_char(args));
	case 's':
		return (print_string(args));
	case 'd':
	case 'i':
		return (print_integer(args));
	case 'b':
		return (print_binary(args));
	case 'u':
		return (print_unsigned(args));
	case 'o':
		return (print_octal(args));
	case 'x':
		return (print_hex(args, 0));
	case 'X':
		return (print_hex(args, 1));
	case '%':
		putchar('%');
		return (1);
	default:
		putchar('%');
		putchar(specifier);
		return (2);
	}
}

/**
 * _printf - Custom implementation of printf function
 * @format: Format string containing conversion specifiers
 *
 * Return: The number of characters printed (excluding the null byte
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
			count += print_conversion_specifier(*format, args);
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
