#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;

    len = _printf("Let's try to _printf a simple sentence.\n");
    _printf("Length: [%d]\n", len);

    _printf("Character: [%c]\n", 'H');
    _printf("String: [%s]\n", "I am a string !");

    _printf("Integer: [%d]\n", 123);
    _printf("Negative Integer: [%i]\n", -456);

    _printf("Percent: [%%]\n");

    return (0);
}

