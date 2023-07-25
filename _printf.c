#include <unistd>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom implementation of printf function
 * @format: Format string containing conversion specifiers
 * %c: first conversion specifiers
 * %s: second conversion specifiers
 * %%: third conversion specifier
 *
 * Description: This function produces output
 * according to a format string
 * that may contain conversion specifiers for characters,
 * strings, and integers.
 *
 * Return: The number of characters printed
 * (excluding the null byte used to end
 *  output to strings).
 */
int _printf(const char *format, ...)
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
                    str = va_arg(args, char *);
                    while (*str)
                        putchar(*str), str++, count++;
                    break;
                case '%':
                    putchar('%'), count++;
                    break;
                default:
                    putchar('%'), putchar(*format), count += 2;
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
