#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_integer(va_list args);
int print_binary(va_list args);
int print_conversion_specifier(char specifier, va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);
int print_unsigned(va_list args);
#endif /* MAIN_H */
