#include "main.h"
/**
 * _printf - Custom implementation of printf function
 * @format: Format string containing conversion specifiers
 *
 * Description: This function produces output
 * according to a format string
 * that may contain conversion specifiers for
 * characters, strings, and integers.
 *
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;
char c;
const char *str;

while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
c = va_arg(args, int);
putchar(c);
count++;
break;
case 's':
str = va_arg(args, const char*);
while (*str != '\0')
{
putchar(*str);
str++;
count++;
}
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
